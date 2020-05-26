/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:06:07 by nagresel          #+#    #+#             */
/*   Updated: 2020/04/27 09:59:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	loop_manager(void *data)
{
	t_params	*dt;

	dt = (t_params*)data;
	if (dt->img.id)
		mlx_destroy_image(dt->win.mlx_id, dt->img.id);
	ft_fillin_image(dt);
	ft_key_manager(dt);
	return (0);
}
