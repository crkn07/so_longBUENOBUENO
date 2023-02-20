/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moments_tester.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:12:02 by jisokang          #+#    #+#             */
/*   Updated: 2023/02/17 12:33:46 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	exit_tester(t_game *game)
{
	int	x;
	int	y;

	x = game->player.spr.x;
	y = game->player.spr.y;
	if (game->maps.coord[y][x] == 'E'
		&& game->flag.collect_all && !game->flag.player_walk)
	{
		ft_putstr_fd(ORANGE"=*=*=*=*=*=*=*=*=*=*=\n\n"RESET, 1);
		ft_putstr_fd(GREEN"THANKS FOR PLAYING\n\n\n"RESET, 1);
		ft_putstr_fd(LBLUE"Created by Cristian Torres\n"RESET, 1);
		ft_putstr_fd(BLUE"       42 Madrid          \n"RESET, 1);
		if (GAME_MODE)
		{
			ft_putstr_fd(" Please press [ESC] to exit\n"RESET, 1);
			ft_putstr_fd("or press [R] to retry\n\n"RESET, 1);
		}
		ft_putstr_fd(ORANGE"=*=*=*=*=*=*=*=*=*=*=\n"RESET, 1);
		game->flag.game_scene = GAME_ENDING;
	}
}

void	moments_tester(t_game *game)
{
	if (game->maps.cnt.c == game->player.item)
		game->flag.collect_all = TRUE;
	exit_tester(game);
	if (game->flag.game_scene != GAME_INITIATED && !GAME_MODE)
		close_game(game);
}
