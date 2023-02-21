/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:16:05 by crtorres          #+#    #+#             */
/*   Updated: 2023/02/21 15:24:35 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
