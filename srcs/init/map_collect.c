/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_collect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:36:39 by nagresel          #+#    #+#             */
/*   Updated: 2020/05/13 14:48:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_data_collect_checker(t_params *dt)
{
	if (!(dt->screenresolution_iscollect == 1 &&
				dt->nowalltextpath_iscollect == 1 &&
				dt->sowalltextpath_iscollect == 1 &&
				dt->eawalltextpath_iscollect == 1 &&
				dt->wewalltextpath_iscollect == 1 &&
				dt->spextpath_iscollect == 1 &&
				dt->color_ceiling_iscollect == 1 &&
				dt->color_floor_iscollect == 1))
	{
		dt->error_nb = 8;
		dt->ft_error = ft_parsing_error_mngt;
	}
}

void		ft_map_collect(char **line, t_params *dt)
{
	char *str;
	char *s;

	if (dt->is_map_started == FALSE)
	{
		ft_data_collect_checker(dt);
		if (!(dt->maptemp = ft_strdup(*line)))
			ft_root_error(dt, 6, ft_map_error_mngt);
		dt->is_map_started = TRUE;
	}
	else
	{
		if (!(str = ft_strjoin(dt->maptemp, "/")))
			ft_root_error(dt, 6, ft_map_error_mngt);
		free(dt->maptemp);
		if (!(s = ft_strdup(*line)))
			ft_root_error(dt, 6, ft_map_error_mngt);
		if (!(dt->maptemp = ft_strjoin(str, s)))
			ft_root_error(dt, 6, ft_map_error_mngt);
		free(s);
		free(str);
	}
}
