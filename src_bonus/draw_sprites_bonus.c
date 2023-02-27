/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:55:32 by crtorres          #+#    #+#             */
/*   Updated: 2023/02/27 14:11:50 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	draw_sprites(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->maps.rows)
	{
		j = 0;
		while (j < game->maps.cols)
		{
			if (game->player.spr.x == j && game->player.spr.y == i)
				print_player(game);
			if (game->enemy.x == j && game->enemy.y == i)
				print_enemy(game);
			if (game->enemy2.x == j && game->enemy2.y == i)
				print_enemy2(game);
			j++;
		}
		i++;
	}
}
