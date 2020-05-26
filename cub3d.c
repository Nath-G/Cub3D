/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:07:21 by nagresel          #+#    #+#             */
/*   Updated: 2020/05/14 11:47:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int ac, char **av)
{
	t_params dt;

	ft_bzero(&dt, sizeof(dt));
	ft_init_game(ac, av, &dt);
	if (!(dt.ray.z_buffer = (double *)malloc(sizeof(*dt.ray.z_buffer) *
			dt.win.screenwidth)))
		ft_parsing_error_mngt(&dt, 9);
	if (dt.ft_error)
		ft_root_error(&dt, dt.error_nb, dt.ft_error);
	if ((dt.win.mlx_id = (int *)mlx_init()) < 0)
		ft_mlx_error_mngt(&dt, 0);
	check_maxsize_resolution(&dt);
	if (dt.has_to_save == TRUE)
		ft_fillin_image(&dt);
	if ((dt.win.id = (int *)mlx_new_window(dt.win.mlx_id, dt.win.screenwidth,
					dt.win.screenheight, "Cub3D Nath G. Project")) < 0)
		ft_mlx_error_mngt(&dt, 1);
	mlx_hook(dt.win.id, 2, 1L << 0, event_key_pressed, (void *)&dt);
	mlx_hook(dt.win.id, 3, 1L << 1, event_key_released, (void *)&dt);
	mlx_hook(dt.win.id, 17, 1L << 17, event_destroy_window, (void *)&dt);
	mlx_loop_hook(dt.win.mlx_id, loop_manager, &dt);
	mlx_loop(dt.win.mlx_id);
	return (0);
}
