/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_enemy2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:55:32 by crtorres          #+#    #+#             */
/*   Updated: 2023/02/27 15:33:25 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

static t_img	*get_spr_enemy2(t_game *game, int dir)
{
	t_img	*spr;

	spr = &(game->enemy2.imgx[dir][0]);
	return (spr);
}

void	print_enemy2_walk(t_game *game, t_spr *enemy2, t_img *sprite, int dir)
{
	int	x;
	int	y;

	game->flag.held_keys = TRUE;
	x = (enemy2->x0 * TILE_SIZE)
		+ (game->dir2coord[dir].x * enemy2->i);
	y = ((enemy2->y0 - 1) * TILE_SIZE)
		+ (game->dir2coord[dir].y * enemy2->i);
	ft_put_img(game, sprite->ptr, x, y);
	enemy2->i += ENEMY_SPEED;
	if (enemy2->x * TILE_SIZE == x && (enemy2->y - 1) * TILE_SIZE == y)
	{
		enemy2->i = 0;
		game->flag.held_keys = FALSE;
		game->flag.enemy2_walk = FALSE;
		game->flag.game_scene = GAME_OVER;
		ft_putstr_fd(RED"=*=*=*=*=*=*=*=*=*=*=\n\n"RESET, 1);
		ft_putstr_fd(RED"     GAME OVER     \n"RESET, 1);
		ft_putstr_fd(RED"     YOU DIED      \n"RESET, 1);
		ft_putstr_fd(ROSE"Please press [ESC] to exit\n"RESET, 1);
		ft_putstr_fd(ROSE" or press [R] to retry\n"RESET, 1);
	}
}

void	enemy2_look_player(t_game *game)
{
	int	x;
	int	y;
	int	i;
	int	dir;

	i = 0;
	dir = game->enemy2.dir;
	while (!game->flag.enemy2_walk)
	{
		x = game->enemy2.x + game->dir2coord[dir].x * i;
		y = game->enemy2.y + game->dir2coord[dir].y * i;
		if (game->maps.coord[y][x] == '1')
			return ;
		if (game->player.spr.x == x && game->player.spr.y == y)
		{
			game->flag.held_keys = TRUE;
			game->flag.enemy2_walk = TRUE;
			game->enemy2.x0 = game->enemy2.x;
			game->enemy2.y0 = game->enemy2.y;
			game->enemy2.x = x - game->dir2coord[dir].x;
			game->enemy2.y = y - game->dir2coord[dir].y;
			return ;
		}
		i++;
	}
}

void	print_enemy2(t_game *game)
{
	int		dir;
	t_spr	*enemy2;
	t_img	*sprite;

	dir = game->enemy2.dir;
	enemy2 = &(game->enemy2);
	sprite = get_spr_enemy2(game, dir);
	if (game->flag.enemy2_walk && !game->flag.player_walk)
		print_enemy2_walk(game, enemy2, sprite, dir);
	else
		ft_put_img64(game, sprite->ptr, enemy2->x0, enemy2->y0 - 1);
}
