/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:14:05 by jisokang          #+#    #+#             */
/*   Updated: 2023/02/14 00:37:40 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	reset_game(t_game *game)
{
	ft_putstr_fd("RESET\n", 1);
	game->flag.game_scene = GAME_INITIATED;
	free(game->collec.clst);
	init_collectable(game);
	draw_comp_by_coord(game);
	launch_player(game);
	init_enemy(game);
	init_flags(game);
	return (0);
}
