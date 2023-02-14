/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 04:34:08 by jisokang          #+#    #+#             */
/*   Updated: 2023/02/14 00:13:07 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit(0);
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
