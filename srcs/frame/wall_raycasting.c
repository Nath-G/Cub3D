/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:57:42 by nagresel          #+#    #+#             */
/*   Updated: 2020/04/28 18:09:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_start_n_end_calculation(t_params *dt)
{
	if (dt->ray.side == 0)
	{
		dt->ray.perp_wall_dist = (dt->ray.map_x - dt->player.pos_x +
			(1 - dt->ray.step_x) / 2) / dt->ray.dir_x;
		dt->texture.wall_x = dt->player.pos_y + dt->ray.perp_wall_dist *
			dt->ray.dir_y;
	}
	else
	{
		dt->ray.perp_wall_dist = (dt->ray.map_y - dt->player.pos_y +
				(1 - dt->ray.step_y) / 2) / dt->ray.dir_y;
		dt->texture.wall_x = dt->player.pos_x + dt->ray.perp_wall_dist *
			dt->ray.dir_x;
	}
	dt->texture.wall_x -= floor(dt->texture.wall_x);
	dt->texture.wall_x = 1 - dt->texture.wall_x;
	dt->ray.line_height = (int)(dt->win.screenheight / dt->ray.perp_wall_dist);
	dt->ray.draw_start = -dt->ray.line_height / 2 + dt->win.screenheight / 2;
	dt->ray.draw_end = dt->ray.line_height / 2 + dt->win.screenheight / 2;
}

static void	wall_distance_calc(t_params *dt)
{
	dt->ray.hit = 0;
	dt->ray.side = 0;
	while (dt->ray.hit == 0)
	{
		if (dt->ray.side_dist_x < dt->ray.side_dist_y)
		{
			dt->ray.side_dist_x += dt->ray.delta_dist_x;
			dt->ray.map_x += dt->ray.step_x;
			dt->ray.side = 0;
		}
		else
		{
			dt->ray.side_dist_y += dt->ray.delta_dist_y;
			dt->ray.map_y += dt->ray.step_y;
			dt->ray.side = 1;
		}
		if (dt->map.maptab[dt->ray.map_y][dt->ray.map_x] == '1')
			dt->ray.hit = 1;
	}
}

static void	ray_step_n_side_distance_calculation(t_params *dt)
{
	if (dt->ray.dir_x < 0.0)
	{
		dt->ray.step_x = -1;
		dt->ray.side_dist_x = (dt->player.pos_x - dt->ray.map_x) *
			dt->ray.delta_dist_x;
	}
	else
	{
		dt->ray.step_x = 1;
		dt->ray.side_dist_x = (dt->ray.map_x + 1.0 - dt->player.pos_x) *
			dt->ray.delta_dist_x;
	}
	if (dt->ray.dir_y < 0.0)
	{
		dt->ray.step_y = -1;
		dt->ray.side_dist_y = (dt->player.pos_y - dt->ray.map_y) *
			dt->ray.delta_dist_y;
	}
	else
	{
		dt->ray.step_y = 1;
		dt->ray.side_dist_y = (dt->ray.map_y + 1.0 - dt->player.pos_y) *
			dt->ray.delta_dist_y;
	}
}

static void	ray_position_n_direction_calculation(t_params *dt, int x)
{
	dt->ray.camera_x = 2 * x / (double)dt->win.screenwidth - 1;
	dt->ray.dir_x = dt->player.dir_x + dt->player.plane_x * dt->ray.camera_x;
	dt->ray.dir_y = dt->player.dir_y + dt->player.plane_y * dt->ray.camera_x;
	dt->ray.map_x = (int)dt->player.pos_x;
	dt->ray.map_y = (int)dt->player.pos_y;
	dt->ray.delta_dist_x = fabs(1 / dt->ray.dir_x);
	dt->ray.delta_dist_y = fabs(1 / dt->ray.dir_y);
}

void		display_wall(t_params *dt)
{
	int x;
	int y;
	int txtnb;

	x = -1;
	while (++x < dt->win.screenwidth)
	{
		ray_position_n_direction_calculation(dt, x);
		ray_step_n_side_distance_calculation(dt);
		wall_distance_calc(dt);
		draw_start_n_end_calculation(dt);
		y = dt->ray.draw_start - 1;
		if (y < -1)
			y = -1;
		txtnb = wall_texture_root(dt);
		while (++y < dt->ray.draw_end && y < dt->win.screenheight)
		{
			dt->texture.text_x = (int)(dt->texture.wall_x *
				dt->text[txtnb].width);
			dt->texture.text_y = (int)((y - dt->ray.draw_start) / (double)(dt->
				ray.draw_end - dt->ray.draw_start) * dt->text[txtnb].height);
			ft_colortexture_address(dt, x, y, txtnb);
		}
		dt->ray.z_buffer[x] = dt->ray.perp_wall_dist;
	}
}
