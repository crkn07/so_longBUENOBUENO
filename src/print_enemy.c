/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:01:18 by crtorres          #+#    #+#             */
/*   Updated: 2023/02/21 15:20:39 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_img	*get_spr_enemy(t_game *game, int dir)
{
	t_img	*spr;

	spr = &(game->enemy.imgx[dir][0]);
	return (spr);
}

void	print_enemy_walk(t_game *game, t_spr *enemy, t_img *sprite, int dir)
{
	int	x;
	int	y;

	game->flag.held_keys = TRUE;
	x = (enemy->x0 * TILE_SIZE)
		+ (game->dir2coord[dir].x * enemy->i);
	y = ((enemy->y0 - 1) * TILE_SIZE)
		+ (game->dir2coord[dir].y * enemy->i);
	ft_put_img(game, sprite->ptr, x, y);
	enemy->i += ENEMY_SPEED;
	if (enemy->x * TILE_SIZE == x && (enemy->y - 1) * TILE_SIZE == y)
	{
		enemy->i = 0;
		game->flag.held_keys = FALSE;
		game->flag.enemy_walk = FALSE;
		game->flag.game_scene = GAME_OVER;
		ft_putstr_fd(RED"=*=*=*=*=*=*=*=*=*=*=\n\n"RESET, 1);
		ft_putstr_fd(RED"     GAME OVER     \n"RESET, 1);
		ft_putstr_fd(RED"     YOU DIED      \n"RESET, 1);
		ft_putstr_fd(ROSE"Please press [ESC] to exit\n"RESET, 1);
		ft_putstr_fd(ROSE" or press [R] to retry\n"RESET, 1);
	}
}

void	print_enemy(t_game *game)
{
	int		dir;
	t_spr	*enemy;
	t_img	*sprite;

	dir = game->enemy.dir;
	enemy = &(game->enemy);
	sprite = get_spr_enemy(game, dir);
	if (game->flag.enemy_walk && !game->flag.player_walk)
		print_enemy_walk(game, enemy, sprite, dir);
	else
		ft_put_img64(game, sprite->ptr, enemy->x0, enemy->y0 - 1);
}
