/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_position_collect.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:59:43 by nagresel          #+#    #+#             */
/*   Updated: 2020/04/27 12:21:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_sprite	*ft_sprite_init(t_params *dt, int spirite_nb)
{
	t_sprite *sp;

	if (!(sp = (t_sprite*)malloc(sizeof(*sp) * spirite_nb)))
		ft_parsing_error_mngt(dt, 9);
	return (sp);
}

void			ft_sprite_position_collect(t_params *dt)
{
	int x;
	int y;
	int i;

	y = -1;
	i = -1;
	dt->sp = ft_sprite_init(dt, dt->sprite_nb);
	while (++y < dt->map.mapheight)
	{
		x = -1;
		while (++x < dt->map.mapwidth && dt->map.maptab[y][x])
		{
			if (dt->map.maptab[y][x] == '2')
			{
				dt->sp[++i].x = x;
				dt->sp[i].y = y;
			}
		}
	}
}
