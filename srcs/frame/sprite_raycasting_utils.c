/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_raycasting_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:18:39 by nagresel          #+#    #+#             */
/*   Updated: 2020/04/28 18:22:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_distance_player_sprites_calc_greater(t_params *dt, int i)
{
	int sp_dist_1;
	int sp_dist_2;

	sp_dist_1 = ((dt->player.pos_x - dt->sp[i].x) * (dt->player.pos_x -
		dt->sp[i].x) + (dt->player.pos_y - dt->sp[i].y) *
		(dt->player.pos_y - dt->sp[i].y));
	sp_dist_2 = ((dt->player.pos_x - dt->sp[i + 1].x) * (dt->player.pos_x -
		dt->sp[i + 1].x) + (dt->player.pos_y - dt->sp[i + 1].y) *
		(dt->player.pos_y - dt->sp[i + 1].y));
	if (sp_dist_1 < sp_dist_2)
		return (1);
	return (0);
}

void		sprite_order(t_params *dt)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = 0;
	while (i < dt->sprite_nb - 1)
	{
		j = i + 1;
		while (j < dt->sprite_nb)
		{
			if (is_distance_player_sprites_calc_greater(dt, i) == TRUE)
			{
				temp = dt->sp[i];
				dt->sp[i] = dt->sp[i + 1];
				dt->sp[i + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
