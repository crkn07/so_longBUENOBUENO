/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 03:54:23 by jisokang          #+#    #+#             */
/*   Updated: 2023/02/03 11:32:24 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	init_dir(t_game *game)
{
	game->dir2coord[DIR_NONE] = (t_coord){0, 0};
	game->dir2coord[DIR_NORTH] = (t_coord){0, -1};
	game->dir2coord[DIR_SOUTH] = (t_coord){0, 1};
	game->dir2coord[DIR_WEST] = (t_coord){-1, 0};
	game->dir2coord[DIR_EAST] = (t_coord){1, 0};
}
