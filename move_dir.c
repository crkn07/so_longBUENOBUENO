/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 05:54:32 by jisokang          #+#    #+#             */
/*   Updated: 2023/02/13 21:14:22 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	move_dir(t_game *game, t_spr *sprite, int dir)
{
	sprite->x0 = sprite->x;
	sprite->y0 = sprite->y;
	sprite->dir = dir;
	if (sprite->frame > sprite->frame_max)
		sprite->frame = 0;
	sprite->frame++;
	if (!check_collision(game, sprite, dir))
	{
		sprite->move = TRUE;
		sprite->x += game->dir2coord[dir].x;
		sprite->y += game->dir2coord[dir].y;
		sprite->step++;
		if (sprite == &(game->player.spr))
			game->flag.step_cnt = TRUE;
	}
	else
		sprite->move = FALSE;
	game->flag.player_walk = TRUE;
}

void	move_north(t_game *game, t_spr *sprite)
{
	move_dir(game, sprite, DIR_NORTH);
}

void	move_south(t_game *game, t_spr *sprite)
{
	move_dir(game, sprite, DIR_SOUTH);
}

void	move_west(t_game *game, t_spr *sprite)
{
	move_dir(game, sprite, DIR_WEST);
}

void	move_east(t_game *game, t_spr *sprite)
{
	move_dir(game, sprite, DIR_EAST);
}
