/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:05:07 by nagresel          #+#    #+#             */
/*   Updated: 2020/05/14 11:52:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_isprint_exceptspace(int c)
{
	if (!(c > 32 && c <= 126))
		return (0);
	return (1);
}

int		ft_is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int		ft_strlen_withoutspace(char *str)
{
	int count;

	count = 0;
	if (!str || !*str)
		return (0);
	while (*str)
	{
		if (*str != ' ')
			count++;
		str++;
	}
	return (count);
}

int		ft_sprite_counter(t_params *dt)
{
	int i;
	int sprite_nb;

	i = 0;
	sprite_nb = 0;
	while (dt->maptemp[i])
	{
		if (dt->maptemp[i] == '2')
			sprite_nb++;
		i++;
	}
	return (sprite_nb);
}

void	check_maxsize_resolution(t_params *dt)
{
	int x;
	int y;

	mlx_get_screen_size(dt->win.mlx_id, &x, &y);
	if (dt->win.screenwidth > x)
		dt->win.screenwidth = x;
	if (dt->win.screenheight > y)
		dt->win.screenheight = y;
}
