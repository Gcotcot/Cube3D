# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdubois <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 14:42:03 by rdubois           #+#    #+#              #
#    Updated: 2023/10/09 17:05:43 by gcot             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = gcc
FLAGS = -g -Wall -Wextra -Werror #-fsanitize=address

MLXA_PATH = ./mlx/
MLX_FLAGS = -L$(MLXA_PATH) -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd
MLX_EX = $(MLX) $(MLX_FLAGS)

INC = /usr/include
INCLIB = $(INC) -O3 -I.. -g

LIB = ./libft/libft.a
MLX = ./mlx/libmlx.a

OBJ = $(SRC: .c=.o) \
	$(GNL: .c=.o)

SRC = main.c \
	src/set_minilibx.c \
	src/map_set.c \
	src/map_set2.c \
	src/map_set3.c \
	src/map_set4.c \
	src/map_set5.c \
	src/utils.c \
	src/mini_map.c \
	src/draw.c \
	src/draw2.c \
	src/raycaster.c \
	src/controls.c \
	src/keypress.c \
	src/mouse.c \
	src/verif_wall.c

GNL = gnl/get_next_line.c \
	gnl/get_next_line_utils.c

all: lib mlx $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIB) $(MLX_EX) -o $(NAME)

mlx:
	make -s -C mlx

lib:
	make -s -C libft

obj:
	mkdir -p obj

clean:
	make clean -sC libft
	make clean -sC mlx	
	rm -rf $(OBJ)

fclean: 
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY : mlx
