/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:55:32 by crtorres          #+#    #+#             */
/*   Updated: 2023/02/21 15:31:51 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

static void	draw_in_map(t_game *game, int i, int j)
{
	if (game->maps.coord[i][j] == '1')
		ft_put_img64(game, game->tile.t1.ptr, j, i);
	else if (game->maps.coord[i][j] == 'E')
	{
		if (game->flag.collect_all)
			ft_put_img64(game, game->tile.tl.ptr, j, i);
		else
		{
			ft_put_img64(game, game->tile.t0.ptr, j, i);
			ft_put_img64(game, game->tile.ts.ptr, j, i);
		}
	}
	else
		ft_put_img64(game, game->tile.t0.ptr, j, i);
}

void	print_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->maps.rows)
	{
		j = 0;
		while (j < game->maps.cols)
		{
			draw_in_map(game, i, j);
			j++;
		}
		i++;
	}
}
