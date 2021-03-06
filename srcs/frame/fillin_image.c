/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillin_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:04:16 by nagresel          #+#    #+#             */
/*   Updated: 2020/05/08 15:00:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_fillin_image(t_params *dt)
{
	dt->img.id = mlx_new_image(dt->win.mlx_id, dt->win.screenwidth,
			dt->win.screenheight);
	dt->img.address = mlx_get_data_addr(dt->img.id, &dt->img.bits_per_pixel,
			&dt->img.size_line, &dt->img.endian);
	dt->img.width = dt->win.screenwidth;
	dt->img.height = dt->win.screenheight;
	ft_display_background_color(dt, "ceiling", 0, dt->win.screenheight / 2);
	ft_display_background_color(dt, "floor", dt->win.screenheight / 2,
			dt->win.screenheight);
	load_texture(dt);
	display_wall(dt);
	display_sprite(dt);
	unload_texture(dt);
	if (dt->has_to_save == TRUE)
	{
		create_bmp(dt);
		ft_clean_n_free(dt);
		write(1, "image is save\n", 14);
		exit(EXIT_SUCCESS);
	}
	mlx_put_image_to_window(dt->win.mlx_id, dt->win.id, dt->img.id, 0, 0);
}
