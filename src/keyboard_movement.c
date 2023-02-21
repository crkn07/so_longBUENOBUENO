/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:34:08 by crtorres          #+#    #+#             */
/*   Updated: 2023/02/21 15:25:55 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_dir(t_game *game)
{
	game->dir2coord[DIR_NONE] = (t_coord){0, 0};
	game->dir2coord[DIR_NORTH] = (t_coord){0, -1};
	game->dir2coord[DIR_SOUTH] = (t_coord){0, 1};
	game->dir2coord[DIR_WEST] = (t_coord){-1, 0};
	game->dir2coord[DIR_EAST] = (t_coord){1, 0};
}

int	keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_message("game finished", game);
	else if (keycode == KEY_RETURN && game->flag.game_scene == GAME_START)
		game->flag.game_scene = GAME_INITIATED;
	else if (keycode == KEY_RESET && game->flag.game_scene != GAME_START)
		reset_game(game);
	else if (!game->flag.held_keys && game->flag.game_scene == GAME_INITIATED)
	{
		if (keycode == KEY_W || keycode == KEY_UP)
			move_north(game, &(game->player.spr));
		else if (keycode == KEY_A || keycode == KEY_LEFT)
			move_west(game, &(game->player.spr));
		else if (keycode == KEY_S || keycode == KEY_DOWN)
			move_south(game, &(game->player.spr));
		else if (keycode == KEY_D || keycode == KEY_RIGHT)
			move_east(game, &(game->player.spr));
	}
	return (0);
}
