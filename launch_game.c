/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:09:39 by jisokang          #+#    #+#             */
/*   Updated: 2023/02/16 11:01:58 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	launch_window(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	if (!game->mlx)
		error_message("mlx_init fail\n");
	width = game->maps.cols * TILE_SIZE;
	height = game->maps.rows * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (!game->win)
		error_message("launch_window fail\n");
}

void	launch_player(t_game *game)
{
	game->player.step = 0;
	game->player.item = 0;
	game->player.spr.step = 0;
	game->player.spr.frame = 0;
	game->player.spr.frame_max = P_MAX_FRAME;
	game->player.spr.i = 0;
	game->player.spr.dir = DIR_SOUTH;
	game->player.spr.move = TRUE;
	game->player.death = 0;
}

void	init_flags(t_game *game)
{
	game->flag.collect_all = FALSE;
	game->flag.held_keys = FALSE;
	game->flag.player_walk = FALSE;
	game->flag.enemy_walk = FALSE;
	game->flag.step_cnt = FALSE;
	game->fps = 0;
}

int	check_game_mode(int mode)
{
	if (mode == MANDATORY)
		return (GAME_INITIATED);
	else
		return (GAME_START);
}

void	launch_game(t_game *game)
{
	launch_window(game);
	init_dir(game);
	init_img(game);
	init_enemy(game);
	launch_player(game);
	init_flags(game);
	game->flag.game_scene = check_game_mode(GAME_MODE);
}
