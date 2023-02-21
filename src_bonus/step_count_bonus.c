/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_count_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:55:32 by crtorres          #+#    #+#             */
/*   Updated: 2023/02/21 15:32:10 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

static void	print_step_count(t_game *game)
{
	ft_putstr_fd("Step : ", 1);
	ft_putnbr_fd(game->player.spr.step, 1);
	ft_putstr_fd("\n", 1);
	game->flag.step_cnt = FALSE;
}

void	draw_step_count(t_game *game)
{
	char	*str;

	str = ft_itoa(game->player.spr.step);
	if (game->flag.step_cnt && game->flag.game_scene == GAME_INITIATED)
		print_step_count(game);
	ft_put_img64(game, game->tile.tb.ptr, 0, 0);
	mlx_string_put(game->mlx, game->win, 25, 27, 0x000000, str);
	free(str);
}
