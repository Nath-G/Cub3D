/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapformat_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:45:44 by nagresel          #+#    #+#             */
/*   Updated: 2020/05/07 14:06:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_init_map_size(t_params *dt)
{
	int i;
	int width;

	dt->map.mapwidth = ft_strlen(dt->map.maptab[0]);
	i = 0;
	while (dt->map.maptab[i++])
		dt->map.mapheight++;
	i = 1;
	while (i < dt->map.mapheight)
	{
		if ((width = ft_strlen(dt->map.maptab[i])) > dt->map.mapwidth)
			dt->map.mapwidth = width;
		i++;
	}
}

static void	ft_map_caractere_checker(t_params dt)
{
	int i;
	int j;

	i = 0;
	while (dt.map.maptab[i] && i < dt.map.mapheight)
	{
		j = 0;
		while (dt.map.maptab[i][j] && j < dt.map.mapwidth)
		{
			if (ft_strchr(DIRECTIONS, dt.map.maptab[i][j]) == 0 &&
					ft_strchr(DESCRIPTIONS, dt.map.maptab[i][j]) == 0)
				ft_map_error_mngt(&dt, 3);
			j++;
		}
		i++;
	}
}

static void	map_checker_bck_tracking(int pos_x, int pos_y, char **map,
		t_params dt)
{
	int has_already_check;
	int i;

	i = 0;
	has_already_check = 'c';
	if (pos_x < 0 || pos_x > dt.map.mapwidth || pos_y < 0 ||
			pos_y > dt.map.mapheight - 1 || map[pos_y][pos_x] == ' ')
	{
		while (i < dt.map.mapheight)
		{
			if (map[i])
				free(map[i]);
			i++;
		}
		free(map);
		ft_map_error_mngt(&dt, 4);
	}
	if (map[pos_y][pos_x] == '1' || map[pos_y][pos_x] == has_already_check)
		return ;
	map[pos_y][pos_x] = has_already_check;
	map_checker_bck_tracking(pos_x + 1, pos_y, map, dt);
	map_checker_bck_tracking(pos_x - 1, pos_y, map, dt);
	map_checker_bck_tracking(pos_x, pos_y + 1, map, dt);
	map_checker_bck_tracking(pos_x, pos_y - 1, map, dt);
	return ;
}

char		**duplicate_map(t_params *dt)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * dt->map.mapheight)))
		ft_map_error_mngt(dt, 6);
	while (i < dt->map.mapheight)
	{
		j = 0;
		if (!(tab[i] = malloc(sizeof(*tab) * (ft_strlen(dt->map.maptab[i])
				+ 1))))
			ft_map_error_mngt(dt, 6);
		while (dt->map.maptab[i][j] && j < dt->map.mapwidth)
		{
			tab[i][j] = dt->map.maptab[i][j];
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	return (tab);
}

void		ft_map_checker(t_params *dt)
{
	char	**tab;
	int		pos_x;
	int		pos_y;
	int		i;

	i = 0;
	pos_x = (int)(dt->player.pos_x - 0.5);
	pos_y = (int)(dt->player.pos_y - 0.5);
	ft_init_map_size(dt);
	ft_map_caractere_checker(*dt);
	tab = duplicate_map(dt);
	map_checker_bck_tracking(pos_x, pos_y, tab, *dt);
	i = 0;
	while (i < dt->map.mapheight)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
