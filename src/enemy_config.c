/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:40:23 by jisokang          #+#    #+#             */
/*   Updated: 2023/02/17 12:33:09 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_enemy(t_game *game)
{
	game->enemy.dir = DIR_SOUTH;
	game->enemy.i = 0;
	game->enemy.move = TRUE;
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

void	enemy_behaviour(t_game *game)
{
	if (game->maps.cnt.r > 0)
	{
		if (game->fps % 100 == 0 && !game->flag.enemy_walk)
			spin_like_clock(&(game->enemy));
		looking_at_player(game);
	}
}
