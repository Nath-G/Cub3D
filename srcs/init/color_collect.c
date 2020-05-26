/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_collect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:13:57 by nagresel          #+#    #+#             */
/*   Updated: 2020/05/12 17:37:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_rgb_to_int(char *col, int *rgb, int ret)
{
	while (col[ret] && col[ret] != ',')
		ret++;
	ret++;
	*rgb = ft_atoi(col + ret);
	return (ret);
}

static int	ft_strtoint_color(char *col, int c, t_params *dt)
{
	int	r;
	int	g;
	int	b;
	int i;

	i = 0;
	if ((c == 'F' && dt->color_floor_iscollect == 1) ||
			(c == 'C' && dt->color_ceiling_iscollect == 1))
	{
		dt->error_nb = 7;
		dt->ft_error = ft_parsing_error_mngt;
	}
	r = ft_atoi(col);
	i = ft_rgb_to_int(col, &g, i);
	i = ft_rgb_to_int(col, &b, i);
	if (!((r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255)))
	{
		dt->error_nb = 6;
		dt->ft_error = ft_parsing_error_mngt;
	}
	return (r << 16 | g << 8 | b);
}

static void	ft_color_root(int color, char c, t_params *dt)
{
	if (c == 'F')
	{
		dt->color_floor_iscollect = TRUE;
		dt->win.color_floor = color;
	}
	else if (c == 'C')
	{
		dt->color_ceiling_iscollect = TRUE;
		dt->win.color_ceiling = color;
	}
}

void		ft_color_collect(char *line, t_params *dt)
{
	char	c;
	char	*colors;
	int		i;

	i = 0;
	while (ft_is_space(line[i]) == 1)
		i++;
	c = line[i];
	if (!ft_is_color_format(dt, line))
	{
		dt->error_nb = 6;
		dt->ft_error = ft_parsing_error_mngt;
	}
	i++;
	while (line[i] && ft_is_space(line[i]))
		i++;
	if (!(colors = ft_strdup(line + i)))
	{
		dt->error_nb = 1;
		dt->ft_error = ft_parsing_error_mngt;
	}
	i = ft_strtoint_color(colors, c, dt);
	free(colors);
	ft_color_root(i, c, dt);
}
