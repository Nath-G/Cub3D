# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 16:30:26 by nagresel          #+#    #+#              #
#    Updated: 2020/04/18 11:41:05 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME - COMPLIATOR - FLAGGS -LIBFT ****************************************** #
NAME	= libft.a
OS = $(shell uname)
CC		= gcc
CC_L	= clang
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f


# SRCS *********************************************************************** #
SRCS			= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isdigit.c \
				 ft_isprint.c ft_memccpy.c ft_memcpy.c ft_memset.c ft_strlen.c \
				 ft_memchr.c ft_strncmp.c ft_tolower.c ft_toupper.c \
				 ft_isascii.c ft_memmove.c ft_strchr.c ft_strrchr.c \
				 ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_strdup.c \
				 ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
				 ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
				 ft_putendl_fd.c ft_putnbr_fd.c ft_memcmp.c ft_lstnew_bonus.c \
				 ft_lstsize_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c \
				 ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstmap_bonus.c \
				 ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
				 get_next_line.c get_next_line_utils.c ft_utoa_base.c \
				 ft_ultoa_base.c \
				 srcs_ft_printf/printf.c srcs_ft_printf/format_c.c \
				 srcs_ft_printf/printer_utils.c srcs_ft_printf/conv_handling.c \
				 srcs_ft_printf/flags_handling.c \
				 srcs_ft_printf/conv_handling_utils.c \
				 srcs_ft_printf/format_d.c srcs_ft_printf/format_s.c \
				 srcs_ft_printf/flags_handling_utils.c \
				 srcs_ft_printf/format_x.c srcs_ft_printf/format_u.c \
				 srcs_ft_printf/format_p.c srcs_ft_printf/format_percent.c \
				 srcs_ft_printf/ft_ultoa_base.c srcs_ft_printf/ft_utoa_base.c \
				 		 

# OBJS *********************************************************************** #

OBJS			=	${SRCS:.c=.o}

OBJSBONUS		=	${SRCSBONUS:.c=.o}


# HEADERS ******************************************************************** #
HEADER 			= libft.h get_next_line.h srcs_ft_printf/printf.h

#HEADERBONUS		= libft_bonus.h


# RULES ********************************************************************** #
.c.o:
ifeq (${OS}, Darwin)
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
else
	${CC_L} ${CFLAGS} -c $< -o ${<:.c=.o}
endif

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS} ${HEADER}

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:	all bonus clean fclean re
