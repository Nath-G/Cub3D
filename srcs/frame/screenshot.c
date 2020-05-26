/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <nagresel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 12:53:02 by user42            #+#    #+#             */
/*   Updated: 2020/05/13 16:35:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	int_to_char(unsigned char *c, int i)
{
	ft_bzero(c, 4);
	c[0] = (unsigned char)i;
	c[1] = (unsigned char)(i >> 8);
	c[2] = (unsigned char)(i >> 16);
	c[3] = (unsigned char)(i >> 24);
}

static void	info_header(unsigned char *c, int width, int height, int oct_add)
{
	int file_size;

	file_size = (54 + (width * 3 * height) + oct_add);
	int_to_char(c, 'B');
	c[1] = (unsigned char)'M';
	c[10] = (unsigned char)(54);
	c[14] = (unsigned char)(40);
	int_to_char(c + 18, width);
	int_to_char(c + 22, height);
	c[26] = (unsigned char)(1);
	c[28] = (unsigned char)(24);
}

static void	write_img(t_params *dt, int fd, int oct_add, unsigned char oct_nul)
{
	int				x;
	int				y;
	int				i;
	unsigned char	cp;

	y = dt->win.screenheight;
	while (--y >= 0)
	{
		x = -1;
		while (++x < dt->win.screenwidth)
		{
			i = -1;
			while (++i < 3)
			{
				cp = dt->img.address[x * 4 + y * dt->img.size_line + i];
				if (write(fd, &cp, 1) < 0)
					return ;
			}
		}
	}
	while (oct_add-- > 0)
	{
		if (write(fd, &oct_nul, 1) < 0)
			return ;
	}
}

void		create_bmp(t_params *dt)
{
	int				fd;
	int				oct_add;
	unsigned char	c[54];
	unsigned char	oct_nul;

	oct_add = (54 + dt->win.screenwidth * 3 * dt->win.screenheight) % 4;
	oct_nul = 0;
	ft_bzero(c, 54);
	if ((fd = open("cub3D.bmp", O_RDWR | O_CREAT, 00777 | O_APPEND))
			< 0)
		ft_file_error_mngt(dt, 4);
	info_header(c, dt->win.screenwidth, dt->win.screenheight, oct_add);
	write(fd, c, 54);
	write_img(dt, fd, oct_add, oct_nul);
	close(fd);
}
