/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:15:41 by nagresel          #+#    #+#             */
/*   Updated: 2020/05/06 19:21:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_int_to_rgb(int color, char rgb)
{
	unsigned char *src;
	unsigned char r;
	unsigned char g;
	unsigned char b;

	src = (unsigned char *)&color;
	if (rgb == 'b')
		return (b = src[2]);
	if (rgb == 'g')
		return (g = src[1]);
	if (rgb == 'r')
		return (r = src[0]);
	return (0);
}

void		ft_color_address(t_params *dt, int x, int y, int color)
{
	dt->img.address[(4 * x) + (y * dt->img.size_line) + 0] =
		ft_int_to_rgb(color, 'r');
	dt->img.address[(4 * x) + (y * dt->img.size_line) + 1] =
		ft_int_to_rgb(color, 'g');
	dt->img.address[(4 * x) + (y * dt->img.size_line) + 2] =
		ft_int_to_rgb(color, 'b');
}

void		ft_colortexture_address(t_params *dt, int x, int y, int txtnb)
{
	int text_offset;
	int img_offset;

	img_offset = y * dt->img.size_line + x * dt->img.bits_per_pixel / 8;
	text_offset = dt->texture.text_y * dt->text[txtnb].size_line +
		dt->texture.text_x * (dt->text[txtnb].bits_per_pixel / 8);
	if (txtnb > 3)
		dt->sp_drwn.color = dt->text[txtnb].address[text_offset] +
			dt->text[txtnb].address[text_offset + 1] +
			dt->text[txtnb].address[text_offset + 2];
	if (txtnb < 4 || (txtnb > 3 && dt->sp_drwn.color != 0))
	{
		dt->img.address[img_offset] = dt->text[txtnb].address[text_offset];
		dt->img.address[img_offset + 1] =
			dt->text[txtnb].address[text_offset + 1];
		dt->img.address[img_offset + 2] =
			dt->text[txtnb].address[text_offset + 2];
	}
}
