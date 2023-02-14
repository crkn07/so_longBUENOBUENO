/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:32:14 by jisokang          #+#    #+#             */
/*   Updated: 2023/02/14 00:58:51 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

/**
 * If you print the sprites at the
 * top of the screen first, they
 * do not overlap unnaturally.
 */
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
			else if (game->enemy.x == j && game->enemy.y == i)
				print_enemy(game);
			j++;
		}
		i++;
	}
}
