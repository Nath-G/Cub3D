# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 16:30:26 by nagresel          #+#    #+#              #
#    Updated: 2020/05/25 11:26:44 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME - COMPLIATOR - FLAGGS -LIBFT ****************************************** #
NAME	= Cub3D
OS = $(shell uname)
MLX	= -lmlx -framework OpenGL -framework AppKit
MLX_L	= -lX11 -lXext -lm -lbsd
CC	= gcc
CC_L	= clang
CFLAGS	= -Wall -Wextra -Werror -I./includes
RM	= rm -f
#-fsanitize=address

# SRCS *********************************************************************** #
SRCS	= cub3d.c srcs/init/init_game.c  srcs/init/mapformat_checker.c \
		srcs/init/init_utils.c srcs/init/resolution_collect.c \
		srcs/init/color_collect_utils.c srcs/init/texture_collect.c \
		srcs/init/color_collect.c srcs/init/player_position_collect.c \
		srcs/init/sprite_position_collect.c srcs/init/map_collect.c \
		srcs/frame/wall_raycasting.c srcs/frame/fillin_image.c \
		srcs/frame/sprite_raycasting_utils.c srcs/frame/background.c \
		srcs/frame/frame_utils.c srcs/frame/screenshot.c \
		srcs/frame/sprite_raycasting.c srcs/manager/loop_manager.c \
		srcs/manager/free_manager.c srcs/manager/key_manager.c \
		srcs/manager/error_manager.c srcs/manager/window_manager.c \
	   	srcs/engine/textures.c srcs/engine/player.c srcs/engine/camera.c \

# OBJS *********************************************************************** #

OBJS	=	${SRCS:.c=.o}


# RULES ********************************************************************** #
.c.o:

ifeq (${OS}, Darwin)
			#${CC} ${CFLAGS} -c $< -o ${<:.c=.o} avant
            $(CC) $(CFLAGS) -c $< -o $@

else
			$(CC_L) $(CFLAGS) -c $< -o $@
endif

$(NAME):	${OBJS}
			make all -C ./lib/minilibx
			make all -C ./lib/libft

ifeq (${OS}, Darwin)
			$(CC) $(FLAGS) $(MLX) $(OBJS) -I./lib/libft/libft.a -o $(NAME)
else
			$(CC_L) -o $(NAME) $(OBJS) -L./lib/minilibx -lmlx ./lib/libft/libft.a $(MLX_L)

endif

all:		${NAME}

bonus:		${OBJS} ${OBJSBONUS}
			ar rc ${NAME} ${OBJS} ${OBJSBONUS} 

clean:
			make clean -C ./lib/minilibx 
			make clean -C ./lib/libft
			${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean
			make fclean -C ./lib/libft
			make fclean -C ./lib/minilibx
			${RM} ${NAME}

re:			fclean all

.PHONY:	all libft.a clean fclean re libmlx.a
