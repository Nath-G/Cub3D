/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 11:22:45 by nagresel          #+#    #+#             */
/*   Updated: 2020/05/07 17:50:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	image_creation(t_params *dt, int textnb, char *path)
{
	if (!(dt->text[textnb].id = mlx_xpm_file_to_image(dt->win.mlx_id, path,
			&dt->text[textnb].width, &dt->text[textnb].height)))
	{
		unload_texture(dt);
		ft_file_error_mngt(dt, 3);
	}
	dt->text[textnb].address = mlx_get_data_addr(dt->text[textnb].id,
		&dt->text[textnb].bits_per_pixel, &dt->text[textnb].size_line,
		&dt->text[textnb].endian);
}

void		unload_texture(t_params *dt)
{
	int i;

	i = -1;
	while (++i < 5)
	{
		if (dt->text[i].id)
			mlx_destroy_image(dt->win.mlx_id, dt->text[i].id);
	}
}

void		load_texture(t_params *dt)
{
	int		textnb;
	char	*path;

	textnb = 0;
	while (textnb < 5)
	{
		if (textnb == 0)
			path = dt->eawalltexturepath;
		else if (textnb == 1)
			path = dt->wewalltexturepath;
		else if (textnb == 2)
			path = dt->sowalltexturepath;
		else if (textnb == 3)
			path = dt->nowalltexturepath;
		else if (textnb == 4)
			path = dt->spritetexturepath;
		image_creation(dt, textnb, path);
		textnb++;
	}
}

int			wall_texture_root(t_params *dt)
{
	int txtnb;

	txtnb = -1;
	if (dt->ray.side == 0 && dt->ray.step_x == 1)
		txtnb = 0;
	else if (dt->ray.side == 0 && dt->ray.step_x == -1)
		txtnb = 1;
	else if (dt->ray.side == 1 && dt->ray.step_y == 1)
		txtnb = 2;
	else if (dt->ray.side == 1 && dt->ray.step_y == -1)
		txtnb = 3;
	return (txtnb);
}
