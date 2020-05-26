/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 10:52:02 by nagresel          #+#    #+#             */
/*   Updated: 2020/04/28 17:37:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	turn_right(t_params *dt)
{
	dt->player.old_dir_x = dt->player.dir_x;
	dt->player.dir_x = dt->player.dir_x * cos(dt->player.rtspeed) -
		dt->player.dir_y * sin(dt->player.rtspeed);
	dt->player.dir_y = dt->player.old_dir_x * sin(dt->player.rtspeed) +
		dt->player.dir_y * cos(dt->player.rtspeed);
	dt->player.old_plane_x = dt->player.plane_x;
	dt->player.plane_x = dt->player.plane_x * cos(dt->player.rtspeed) -
		dt->player.plane_y * sin(dt->player.rtspeed);
	dt->player.plane_y = dt->player.old_plane_x * sin(dt->player.rtspeed) +
		dt->player.plane_y * cos(dt->player.rtspeed);
}

void	turn_left(t_params *dt)
{
	dt->player.old_dir_x = dt->player.dir_x;
	dt->player.dir_x = dt->player.dir_x * cos(-dt->player.rtspeed) -
		dt->player.dir_y * sin(-dt->player.rtspeed);
	dt->player.dir_y = dt->player.old_dir_x * sin(-dt->player.rtspeed) +
		dt->player.dir_y * cos(-dt->player.rtspeed);
	dt->player.old_plane_x = dt->player.plane_x;
	dt->player.plane_x = dt->player.plane_x * cos(-dt->player.rtspeed) -
		dt->player.plane_y * sin(-dt->player.rtspeed);
	dt->player.plane_y = dt->player.old_plane_x * sin(-dt->player.rtspeed) +
		dt->player.plane_y * cos(-dt->player.rtspeed);
}
