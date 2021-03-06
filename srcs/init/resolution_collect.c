/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_collect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:03:24 by nagresel          #+#    #+#             */
/*   Updated: 2020/05/14 11:52:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_screenheight_collect(char *str, int *dt_height)
{
	int i;

	i = 0;
	while (str[i] && (ft_is_space(str[i]) == TRUE))
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	while (str[i] && (ft_is_space(str[i])))
		i++;
	*dt_height = ft_atoi(str + i);
}

static int	ft_resolution_data_format(t_params *dt, char *str)
{
	int i;

	i = 0;
	if (str[i] != ' ')
	{
		dt->error_nb = 0;
		dt->ft_error = ft_parsing_error_mngt;
	}
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (!str[i] || !ft_isdigit(str[i]))
	{
		dt->error_nb = 0;
		dt->ft_error = ft_parsing_error_mngt;
	}
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (i);
}

static int	ft_is_resolution_data_format(t_params *dt, char *line)
{
	int i;

	i = 0;
	while (line[i] && ft_is_space(line[i]))
		i++;
	i++;
	i += ft_resolution_data_format(dt, line + i);
	i += ft_resolution_data_format(dt, line + i);
	while (line[i] && ft_is_space(line[i]))
		i++;
	if (line[i])
		return (0);
	return (1);
}

static void	resolution_data_checker(t_params *dt)
{
	if (dt->win.screenwidth < 1 || dt->win.screenheight < 1)
	{
		dt->error_nb = 0;
		dt->ft_error = ft_parsing_error_mngt;
	}
}

void		ft_resolution_collect(char *line, t_params *dt)
{
	int		i;
	char	*str;

	i = 0;
	str = 0;
	if (!ft_is_resolution_data_format(dt, line))
	{
		dt->error_nb = 0;
		dt->ft_error = ft_parsing_error_mngt;
	}
	while (line[i] && ft_is_space(line[i]) == TRUE)
		i++;
	if (!(str = ft_strdup(line + i + 1)))
		ft_root_error(dt, 1, ft_parsing_error_mngt);
	dt->win.screenwidth = ft_atoi(str);
	ft_screenheight_collect(str, &dt->win.screenheight);
	free(str);
	resolution_data_checker(dt);
	if (dt->screenresolution_iscollect == TRUE)
	{
		dt->error_nb = 10;
		dt->ft_error = ft_parsing_error_mngt;
	}
	dt->screenresolution_iscollect = TRUE;
}
