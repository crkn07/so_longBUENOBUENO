/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_config_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:55:32 by crtorres          #+#    #+#             */
/*   Updated: 2023/02/27 19:09:05 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	init_enemies(t_game *game)
{
	game->enemy.dir = DIR_SOUTH;
	game->enemy.i = 0;
	game->enemy.move = TRUE;
	game->enemy2.dir = DIR_NORTH;
	game->enemy2.i = 0;
	game->enemy2.move = TRUE;
}

void	looking_at_player(t_game *game)
{
	int	x;
	int	y;
	int	i;
	int	dir;

	i = 0;
	dir = game->enemy.dir;
	while (!game->flag.enemy_walk)
	{
		x = game->enemy.x + game->dir2coord[dir].x * i;
		y = game->enemy.y + game->dir2coord[dir].y * i;
		if (game->maps.coord[y][x] == '1')
			return ;
		if (game->player.spr.x == x && game->player.spr.y == y)
		{
			game->flag.held_keys = TRUE;
			game->flag.enemy_walk = TRUE;
			game->enemy.x0 = game->enemy.x;
			game->enemy.y0 = game->enemy.y;
			game->enemy.x = x - game->dir2coord[dir].x;
			game->enemy.y = y - game->dir2coord[dir].y;
			return ;
		}
		i++;
	}
}

void	spin_like_clock(t_spr *sprite)
{
	if (sprite->dir == DIR_NONE)
		return ;
	sprite->dir++;
	if (sprite->dir > DIR_EAST)
		sprite->dir = DIR_SOUTH;
}

void	spin_anti_clock(t_spr *sprite)
{
	if (sprite->dir == DIR_NONE)
		return ;
	sprite->dir--;
	if (sprite->dir < DIR_SOUTH)
		sprite->dir = DIR_EAST;
}

void	enemy_behaviour(t_game *game)
{
	if (game->maps.cnt.r > 0)
	{
		if git!game->flag.enemy_walk)
		{
			spin_like_clock(&(game->enemy));
			spin_anti_clock(&(game->enemy2));
		}
		looking_at_player(game);
		enemy2_look_player(game);
	}
}
