/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   covers_change.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:05:07 by crtorres          #+#    #+#             */
/*   Updated: 2023/02/21 15:11:21 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_covers_change(t_game *game)
{
	int		x;
	int		y;

	x = game->maps.cols / 2 - 2;
	y = game->maps.rows / 2 - 2;
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
