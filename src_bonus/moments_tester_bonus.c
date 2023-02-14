/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moments_tester_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:12:02 by jisokang          #+#    #+#             */
/*   Updated: 2023/02/14 00:43:10 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

static void	exit_tester(t_game *game)
{
	int	x;
	int	y;

	x = game->player.spr.x;
	y = game->player.spr.y;
	if (game->maps.coord[y][x] == 'E'
		&& game->flag.collect_all && !game->flag.player_walk)
	{
		ft_putstr_fd("=====================\n\n", 1);
		ft_putstr_fd(CYAN"THANK YOU FOR PLAYING\n\n"RESET, 1);
		ft_putstr_fd("Based on GAME FREAK's\n", 1);
		ft_putstr_fd("  Pokemon Fire Red\n\n", 1);
		if (GAME_MODE)
			ft_putstr_fd(" Press [ESC] to exit\n Press  [R] to retry\n\n", 1);
		ft_putstr_fd("=====================\n", 1);
		game->flag.game_scene = GAME_ENDING;
	}
}

static void	check_death(t_game *game)
{
	int	x;
	int	y;

	x = game->player.spr.x;
	y = game->player.spr.y;
	if (x == game->enemy.x && y == game->enemy.y
		&& !game->flag.enemy_walk)
	{
		ft_putstr_fd("=====================\n\n", 1);
		ft_putstr_fd(RED"      YOU DIED\n\n"RESET, 1);
		ft_putstr_fd(" Press [ESC] to exit\n", 1);
		ft_putstr_fd(" Press  [R] to retry\n\n", 1);
		ft_putstr_fd("=====================\n", 1);
		game->flag.game_scene = GAME_OVER;
	}
}

void	moments_tester(t_game *game)
{
	if (game->maps.cnt.c == game->player.item)
		game->flag.collect_all = TRUE;
	check_death(game);
	exit_tester(game);
	if (game->flag.game_scene != GAME_INITIATED && !GAME_MODE)
		close_game(game);
}
