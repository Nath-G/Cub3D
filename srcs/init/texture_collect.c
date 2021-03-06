/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_collect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:51:25 by nagresel          #+#    #+#             */
/*   Updated: 2020/05/13 14:50:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_is_texture_data_format(char *str)
{
	int i;

	i = 0;
	if (str[0] != ' ')
		return (0);
	while (str[i] && ft_is_space(str[i]))
		i++;
	while (str[i] && ft_isprint_exceptspace(str[i]))
		i++;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (str[i])
		return (0);
	return (1);
}

static int	ft_texture_checker(t_params *dt, t_bool *iscollect)
{
	if (*iscollect == 1)
	{
		dt->error_nb = 5;
		dt->ft_error = ft_parsing_error_mngt;
		return (0);
	}
	else
		*iscollect = 1;
	return (1);
}

static void	ft_wall_texture_root(char *path, char *id,
				t_params *dt)
{
	int i;

	i = 2;
	while (path[i] == ' ')
		i++;
	if (!ft_strncmp(id, "NO", 3))
	{
		if (ft_texture_checker(dt, &dt->nowalltextpath_iscollect))
			dt->nowalltexturepath = ft_strdup(path + i);
	}
	else if (!ft_strncmp(id, "SO", 3))
	{
		if (ft_texture_checker(dt, &dt->sowalltextpath_iscollect))
			dt->sowalltexturepath = ft_strdup(path + i);
	}
	else if (!ft_strncmp(id, "WE", 3))
	{
		if (ft_texture_checker(dt, &dt->wewalltextpath_iscollect))
			dt->wewalltexturepath = ft_strdup(path + i);
	}
	else if (!ft_strncmp(id, "EA", 3))
	{
		if (ft_texture_checker(dt, &dt->eawalltextpath_iscollect))
			dt->eawalltexturepath = ft_strdup(path + i);
	}
}

static void	ft_texture_root(int j, char *id,
				t_params *dt, char *line)
{
	int		i;
	char	*path;

	i = 1;
	if (!(path = ft_strdup(line + j)))
		ft_root_error(dt, 9, ft_parsing_error_mngt);
	if (!ft_strncmp(id, "NO", 3) || !ft_strncmp(id, "SO", 3) ||
			!ft_strncmp(id, "WE", 3) || !ft_strncmp(id, "EA", 3))
		ft_wall_texture_root(path, id, dt);
	else if (!ft_strncmp(id, "S", 2))
	{
		if (ft_texture_checker(dt, &dt->spextpath_iscollect))
		{
			while (path[i] == ' ')
				i++;
			dt->spritetexturepath = ft_strdup(path + i);
		}
	}
	else
		ft_root_error(dt, 4, ft_parsing_error_mngt);
	free(path);
}

void		ft_texture_collect(char *line, t_params *dt)
{
	char	id[3];
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (line[j] && ft_is_space(line[j]))
		j++;
	while (line[++i + j] && ft_isalpha(line[i + j]) && i < 2 &&
			line[i + j] != ' ')
		id[i] = line[i + j];
	id[i] = '\0';
	if (ft_is_texture_data_format(&line[i + j]) == FALSE)
	{
		dt->error_nb = 4;
		dt->ft_error = ft_parsing_error_mngt;
	}
	while (line[i + j] && ft_is_space(line[i + j]))
		i++;
	while (line[i + j] && ft_isprint_exceptspace(line[i + j]))
		i++;
	line[i + j] = '\0';
	ft_texture_root(j, id, dt, line);
}
