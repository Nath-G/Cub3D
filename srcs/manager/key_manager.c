/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:45:51 by nagresel          #+#    #+#             */
/*   Updated: 2020/04/30 13:41:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	event_key_released(int key, void *data)
{
	t_params *dt;

	dt = (t_params*)data;
	if (key == FORWARD && dt->keybuf.fwd_ispress == 1)
		dt->keybuf.fwd_ispress = 0;
	if (key == BACKWARD && dt->keybuf.bkwd_ispress == 1)
		dt->keybuf.bkwd_ispress = 0;
	if (key == RIGHT && dt->keybuf.mvrght_ispress == 1)
		dt->keybuf.mvrght_ispress = 0;
	if (key == LEFT && dt->keybuf.mvlft_ispress == 1)
		dt->keybuf.mvlft_ispress = 0;
	if (key == CAM_RIGHT && dt->keybuf.trnrght_ispress == 1)
		dt->keybuf.trnrght_ispress = 0;
	if (key == CAM_LEFT && dt->keybuf.trnlft_ispress == 1)
		dt->keybuf.trnlft_ispress = 0;
	return (0);
}

int	event_key_pressed(int key, void *data)
{
	t_params *dt;

	dt = (t_params*)data;
	if (key == ESC)
		event_destroy_window(data);
	if (key == FORWARD && dt->keybuf.fwd_ispress == 0)
		dt->keybuf.fwd_ispress = 1;
	if (key == BACKWARD && dt->keybuf.bkwd_ispress == 0)
		dt->keybuf.bkwd_ispress = 1;
	if (key == RIGHT && dt->keybuf.mvrght_ispress == 0)
		dt->keybuf.mvrght_ispress = 1;
	if (key == LEFT && dt->keybuf.mvlft_ispress == 0)
		dt->keybuf.mvlft_ispress = 1;
	if (key == CAM_RIGHT && dt->keybuf.trnrght_ispress == 0)
		dt->keybuf.trnrght_ispress = 1;
	if (key == CAM_LEFT && dt->keybuf.trnlft_ispress == 0)
		dt->keybuf.trnlft_ispress = 1;
	return (0);
}

int	ft_key_manager(void *data)
{
	t_params *dt;

	dt = (t_params*)data;
	if (dt->keybuf.bkwd_ispress == 1)
		move_bkwd(dt);
	if (dt->keybuf.fwd_ispress == 1)
		move_fwd(dt);
	if (dt->keybuf.mvrght_ispress == 1)
		move_right(dt);
	if (dt->keybuf.mvlft_ispress == 1)
		move_left(dt);
	if (dt->keybuf.trnlft_ispress == 1)
		turn_left(dt);
	if (dt->keybuf.trnrght_ispress == 1)
		turn_right(dt);
	return (0);
}
