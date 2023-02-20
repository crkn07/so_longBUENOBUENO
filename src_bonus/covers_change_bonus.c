/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   covers_change_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:05:07 by jisokang          #+#    #+#             */
/*   Updated: 2023/02/20 13:39:06 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	print_covers_change(t_game *game)
{
	int		x;
	int		y;

	x = game->maps.cols / 2 - 3;
	y = game->maps.rows / 2 - 3;
	mlx_clear_window(game->mlx, game->win);
	if (game->flag.game_scene == GAME_START)
		ft_put_img64(game, game->opening.ptr, x, y);
	else if (game->flag.game_scene == GAME_OVER)
		ft_put_img64(game, game->gameover.ptr, x, y);
	else if (game->flag.game_scene == GAME_ENDING)
		ft_put_img64(game, game->ending.ptr, x, y);
	else
		error_message("Cover file error\n");
}
