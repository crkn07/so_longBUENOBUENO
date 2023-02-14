# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    	#
#                                                     +:+ +:+         +:+      #
#    By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 13:51:55 by cyacoub-          #+#    #+#              #
#    Updated: 2023/02/02 18:18:03 by crtorres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -framework OpenGL -framework AppKit
LIBFT = ./libft/libft.a
MLX = ./mlx/libmlx.a
MAIN = main.c
SRC =	collectable.c covers_change.c draw_sprites.c print_enemy.c \
		enemy_config.c error.c moments_tester.c smaller_mlx.c img_init.c \
		launch_game.c keyboard_movement.c map_coord.c print_map.c \
		check_map.c read_map.c check_collision.c move_dir.c \
		move_init.c print_player.c reset_game.c step_count.c \
		util_lst.c \

OBJS = $(SRC:.c=.o)

all: make_libft make_mlx $(NAME)

make_libft:
	@make all -C ./libft

make_mlx:
	@make all -C ./mlx

$(NAME): $(OBJS) $(MAIN) $(SRC)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) $(MAIN) -o $(NAME)
	
bonus: all

clean:
	@rm -f $(OBJS)
	@make clean -C ./libft
	@make clean -C ./mlx

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
	@make clean -C ./mlx

re: fclean all 

.PHONY: all clean fclean re bonus
