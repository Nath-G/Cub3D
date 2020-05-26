/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:17:58 by nagresel          #+#    #+#             */
/*   Updated: 2020/05/01 16:12:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	event_destroy_window(void *data)
{
	t_params *dt;

	dt = (t_params*)data;
	if (dt->img.id)
		mlx_destroy_image(dt->win.mlx_id, dt->img.id);
	mlx_destroy_window(dt->win.mlx_id, dt->win.id);
	ft_free_struct(dt);
	free(dt->win.mlx_id);
	exit(EXIT_SUCCESS);
	return (0);
}
