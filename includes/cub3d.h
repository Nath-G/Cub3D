/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:50:48 by nagresel          #+#    #+#             */
/*   Updated: 2020/05/25 12:12:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/minilibx/mlx.h"
# include <unistd.h>
# include "../lib/libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <stdlib.h>
# include <math.h>

# define TRUE 1
# define FALSE 0
# define DIRECTIONS "NEWS"
# define DESCRIPTIONS "012 "
# define FOV 66.0
# define PI 3.141592
# define ESC 65307
# define FORWARD 122
# define BACKWARD 115
# define LEFT 113
# define RIGHT 100
# define CAM_LEFT 65361
# define CAM_RIGHT 65363

typedef int		t_bool;

typedef struct	s_keybuf
{
	t_bool		fwd_ispress;
	t_bool		bkwd_ispress;
	t_bool		mvrght_ispress;
	t_bool		mvlft_ispress;
	t_bool		trnrght_ispress;
	t_bool		trnlft_ispress;
}				t_keybuf;

typedef struct	s_ray
{
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	double		camera_x;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		*z_buffer;
}				t_ray;

typedef struct	s_map
{
	char		**maptab;
	int			mapwidth;
	int			mapheight;
}				t_map;

typedef	struct	s_img
{
	int			*id;
	char		*address;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct	s_win
{
	int			*mlx_id;
	int			*id;
	int			screenwidth;
	int			screenheight;
	int			color_floor;
	int			color_ceiling;
}				t_win;

typedef struct	s_texture
{
	int			text_x;
	int			text_y;
	double		wall_x;
}				t_text;

typedef struct	s_sprite
{
	int			x;
	int			y;
}				t_sprite;

typedef struct	s_sprite_drawn
{
	double		x;
	double		y;
	double		inv_det;
	double		transform_x;
	double		transform_y;
	int			screen_x;
	int			height;
	int			width;
	int			draw_start_x;
	int			draw_end_x;
	int			draw_start_y;
	int			draw_end_y;
	int			color;
}				t_sp_drwn;

typedef struct	s_user
{
	double		pos_x;
	double		pos_y;
	double		old_dir_x;
	double		old_dir_y;
	double		plane_x;
	double		plane_y;
	double		old_plane_x;
	double		old_plane_y;
	double		dir_x;
	double		dir_y;
	double		speed;
	double		rtspeed;
}				t_user;

typedef struct	s_params
{
	t_win		win;
	t_map		map;
	t_user		player;
	t_ray		ray;
	t_img		img;
	t_keybuf	keybuf;
	t_img		text[5];
	t_text		texture;
	int			sprite_nb;
	t_sprite	*sp;
	t_sp_drwn	sp_drwn;
	char		*sowalltexturepath;
	t_bool		sowalltextpath_iscollect;
	char		*nowalltexturepath;
	t_bool		nowalltextpath_iscollect;
	char		*wewalltexturepath;
	t_bool		wewalltextpath_iscollect;
	char		*eawalltexturepath;
	t_bool		eawalltextpath_iscollect;
	char		*spritetexturepath;
	t_bool		spextpath_iscollect;
	t_bool		screenresolution_iscollect;
	t_bool		color_floor_iscollect;
	t_bool		color_ceiling_iscollect;
	char		*maptemp;
	t_bool		is_map_started;
	t_bool		is_position_defined;
	char		direction;
	t_bool		has_to_save;
	int			error_nb;
	void		*ft_error;
}				t_params;

void			ft_init_game(int ac, char **av, t_params *dt);
void			ft_resolution_collect(char *line, t_params *dt);
void			ft_texture_collect(char *line, t_params *dt);
void			ft_color_collect(char *line, t_params *dt);
void			ft_map_collect(char **line, t_params *dt);
void			ft_map_checker(t_params *dt);
int				ft_is_color_format(t_params *dt, char *line);
void			ft_player_position_collect(t_params *dt);
void			ft_sprite_position_collect(t_params *dt);

void			ft_root_error(t_params *dt, int error_nb,
					void (*ft_error)(t_params *, int));
void			ft_file_error_mngt(t_params *dt, int error_nb);
void			ft_map_error_mngt(t_params *dt, int error_nb);
void			ft_parsing_error_mngt(t_params *dt, int error_nb);
void			ft_mlx_error_mngt(t_params *dt, int error_nb);

void			ft_fillin_image(t_params *dt);
void			display_wall(t_params *dt);
void			ft_display_background_color(t_params *dt, char *area, int start,
					int stop);
void			display_sprite(t_params *dt);
void			sprite_order(t_params *dt);
void			load_texture(t_params *dt);
void			unload_texture(t_params *dt);
int				wall_texture_root(t_params *dt);
void			create_bmp(t_params *dt);

int				event_key_pressed(int key, void *data);
int				event_key_released(int key, void *data);
int				ft_key_manager(void *data);
int				event_destroy_window(void *data);
int				loop_manager(void *data);
void			move_fwd(t_params *data);
void			move_bkwd(t_params *data);
void			move_right(t_params *data);
void			move_left(t_params *data);
void			turn_right(t_params *data);
void			turn_left(t_params *data);

int				ft_isprint_exceptspace(int c);
int				ft_is_space(char c);
int				ft_strlen_withoutspace(char *str);
int				ft_sprite_counter(t_params *dt);
void			check_maxsize_resolution(t_params *dt);

void			ft_color_address(t_params *dt, int x, int y, int color);
void			ft_colortexture_address(t_params *dt, int x, int y, int txtnb);
void			ft_free_struct(t_params *dt);
void			ft_clean_n_free(t_params *dt);

#endif
