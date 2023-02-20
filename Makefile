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
NAME_BONUS = so_long_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
FSANI = -g -fsanitize=address
MLX_FLAGS = -framework OpenGL -framework AppKit
LIBFT = ./libft/libft.a
MLX = ./mlx/libmlx.a
SRC_DIR = ./src/
SRC_B_DIR = ./src_bonus/
LIBRARIES = ./includes/
LIBS_BONUS = ./includes_bonus/

SRC =	main.c collectable.c covers_change.c draw_sprites.c print_enemy.c \
		enemy_config.c error.c moments_tester.c smaller_mlx.c img_init.c \
		launch_game.c keyboard_movement.c map_coord.c print_map.c \
		check_map.c read_map.c move_dir.c print_player.c reset_game.c \
		step_count.c check_rute.c check_route_collect.c util_lst.c \

SRC_B = main_bonus.c collectable_bonus.c covers_change_bonus.c \
		draw_sprites_bonus.c print_enemy_bonus.c enemy_config_bonus.c \
		error_bonus.c moments_tester_bonus.c smaller_mlx_bonus.c \
		img_init_bonus.c launch_game_bonus.c keyboard_movement_bonus.c \
		map_coord_bonus.c print_map_bonus.c check_map_bonus.c read_map_bonus.c \
		move_dir_bonus.c print_player_bonus.c reset_game_bonus.c \
		step_count_bonus.c check_rute_bonus.c check_route_collect_bonus.c \
		util_lst_bonus.c \

SRCS = $(addprefix $(SRC_DIR), $(SRC))
SRCS_BONUS = $(addprefix $(SRC_B_DIR), $(SRC_B))

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: make_libft make_mlx $(NAME)

bonus: make_libft make_mlx $(NAME_BONUS)

make_libft:
	make -C ./libft

make_mlx:
	@make -C ./mlx

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -I $(LIBRARIES) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)


$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -I $(LIBS_BONUS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME_BONUS)
	

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@make clean -C ./libft
	@make clean -C ./mlx

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C ./libft
	@make clean -C ./mlx

re: fclean all


.PHONY: all clean fclean re bonus
