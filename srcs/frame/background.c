/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:58:44 by nagresel          #+#    #+#             */
/*   Updated: 2020/04/24 16:58:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_display_background_color(t_params *dt, char *area, int start,
		int stop)
{
	int y;
	int x;
	int color;

	x = -1;
	if (!ft_strncmp(area, "ceiling", 8))
		color = dt->win.color_ceiling;
	if (!ft_strncmp(area, "floor", 6))
		color = dt->win.color_floor;
	while (++x < dt->win.screenwidth)
	{
		y = start - 1;
		while (++y < stop)
		{
			if (dt->img.address[(4 * x) + (y * dt->img.size_line)] == 0)
				ft_color_address(dt, x, y, color);
		}
	}
}
