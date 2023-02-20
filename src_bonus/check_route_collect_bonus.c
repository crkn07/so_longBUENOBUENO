/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_route_collect_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:55:32 by crtorres          #+#    #+#             */
/*   Updated: 2023/02/20 13:57:06 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

int	valid_path_collect(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->maps.rows)
	{
		y = 0;
		while (y < game->maps.cols)
		{
			if (game->maps.mapcopy[x][y] == 'C')
				error_message("doesn´t reach the collectables");
			y++;
		}
		x++;
	}
	return (TRUE);
}
