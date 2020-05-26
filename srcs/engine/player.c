/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:07:07 by nagresel          #+#    #+#             */
/*   Updated: 2020/04/28 17:36:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_fwd(t_params *dt)
{
	if (dt->map.maptab[(int)(dt->player.pos_y)][(int)(dt->player.pos_x +
			dt->player.dir_x * dt->player.speed)] == '0')
		dt->player.pos_x += dt->player.dir_x * dt->player.speed;
	if (dt->map.maptab[(int)(dt->player.pos_y + dt->player.dir_y *
			dt->player.speed)][(int)(dt->player.pos_x)] == '0')
		dt->player.pos_y += dt->player.dir_y * dt->player.speed;
}

void	move_bkwd(t_params *dt)
{
	if (dt->map.maptab[(int)(dt->player.pos_y)][(int)(dt->player.pos_x -
			dt->player.dir_x * dt->player.speed)] == '0')
		dt->player.pos_x -= dt->player.dir_x * dt->player.speed;
	if (dt->map.maptab[(int)(dt->player.pos_y - dt->player.dir_y *
			dt->player.speed)][(int)(dt->player.pos_x)] == '0')
		dt->player.pos_y -= dt->player.dir_y * dt->player.speed;
}

void	move_right(t_params *dt)
{
	if (dt->map.maptab[(int)dt->player.pos_y][(int)(dt->player.pos_x +
			dt->player.plane_x * dt->player.speed)] == '0')
		dt->player.pos_x += dt->player.plane_x * dt->player.speed;
	if (dt->map.maptab[(int)(dt->player.pos_y + dt->player.plane_y *
			dt->player.speed)][(int)dt->player.pos_x] == '0')
		dt->player.pos_y += dt->player.plane_y * dt->player.speed;
}

void	move_left(t_params *dt)
{
	if (dt->map.maptab[(int)dt->player.pos_y][(int)(dt->player.pos_x -
			dt->player.plane_x * dt->player.speed)] == '0')
		dt->player.pos_x -= dt->player.plane_x * dt->player.speed;
	if (dt->map.maptab[(int)(dt->player.pos_y - dt->player.plane_y *
			dt->player.speed)][(int)dt->player.pos_x] == '0')
		dt->player.pos_y -= dt->player.plane_y * dt->player.speed;
}
