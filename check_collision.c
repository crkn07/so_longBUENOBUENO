/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 04:28:20 by jisokang          #+#    #+#             */
/*   Updated: 2023/02/16 12:43:10 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	check_collision(t_game *game, t_spr *sprite, int dir)
{
	int		x;
	int		y;
	char	c;

	x = game->dir2coord[dir].x;
	y = game->dir2coord[dir].y;
	c = game->maps.coord[sprite->y + y][sprite->x + x];
	if (c == 'R' && !game->flag.enemy_walk)
		return (TRUE);
	if (c == '1')
		return (TRUE);
	else if (c == 'E' && !game->flag.collect_all)
		return (TRUE);
	return (FALSE);
}
