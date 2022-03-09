# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leldiss <leldiss@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 18:17:53 by leldiss           #+#    #+#              #
#    Updated: 2022/03/08 17:42:56 by leldiss          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	so_long
FLAGS = -lmlx -lXext -lX11
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
OBJ = so_long.c \
						ft_printf/flag_cs.c \
						ft_printf/flag_d.c \
						ft_printf/flag_p.c \
						ft_printf/flag_u.c \
						ft_printf/flag_x.c \
						ft_printf/ft_printf.c \
						move_player.c \
						utils.c \
						parse/error.c \
						parse/map_check.c \
						parse/map_read.c
						

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAGS) -o $(NAME)