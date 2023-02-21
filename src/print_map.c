/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:01:55 by crtorres          #+#    #+#             */
/*   Updated: 2023/02/21 15:26:24 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
