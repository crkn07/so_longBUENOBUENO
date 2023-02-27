/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:55:32 by crtorres          #+#    #+#             */
/*   Updated: 2023/02/27 13:05:33 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

int	reset_game(t_game *game)
{
	ft_putstr_fd("RESET\n", 1);
	game->flag.game_scene = GAME_INITIATED;
	free(game->collec.clst);
	init_collectable(game);
	draw_comp_by_coord(game);
	launch_player(game);
	init_enemies(game);
	init_flags(game);
	return (0);
}
