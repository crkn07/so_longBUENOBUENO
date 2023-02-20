/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_coord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 02:14:54 by jisokang          #+#    #+#             */
/*   Updated: 2023/02/13 23:09:14 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	set_component_counter(t_game *game)
{
	game->maps.cnt.p = 0;
	game->maps.cnt.c = 0;
	game->maps.cnt.e = 0;
	game->maps.cnt.r = 0;
}

/**
 * It checks the map for the
 * player, collectibles, enemies, and end point, and stores their coordinates in
 * the appropriate variables
 * 
 * @param game the game structure
 * @param y the y coordinate of the map
 * @param x x-coordinate of the sprite
 */
static void	components_coord(t_game *game, int i, int j)
{
	if (game->maps.coord[i][j] == 'P')
	{
		game->player.spr.x = j;
		game->player.spr.x0 = j;
		game->player.spr.y = i;
		game->player.spr.y0 = i;
		game->maps.cnt.p++;
	}
	else if (game->maps.coord[i][j] == 'C')
	{
		game->maps.cnt.c++;
		clst_add_back(&(game->collec.clst), clst_new(j, i));
	}
	else if (game->maps.coord[i][j] == 'R')
	{
		game->enemy.x = j;
		game->enemy.x0 = j;
		game->enemy.y = i;
		game->enemy.y0 = i;
		game->maps.cnt.r++;
	}
	else if (game->maps.coord[i][j] == 'E')
		game->maps.cnt.e++;
}

int	check_comp_isvalid(t_game *game)
{
	if (!(0 < game->maps.cnt.p && game->maps.cnt.p <= COMPO_P_MAX))
		return (FALSE);
	if (!(0 < game->maps.cnt.c && game->maps.cnt.c <= COMPO_C_MAX))
		return (FALSE);
	if (!(0 < game->maps.cnt.e && game->maps.cnt.e <= COMPO_E_MAX))
		return (FALSE);
	if ((0 <= game->maps.cnt.r && game->maps.cnt.r >= 1))
		return (FALSE);
	return (TRUE);
}

void	draw_comp_by_coord(t_game *game)
{
	int	i;
	int	j;

	set_component_counter(game);
	i = 0;
	while (i < game->maps.rows)
	{
		j = 0;
		while (j < game->maps.cols)
		{
			components_coord(game, i, j);
			j++;
		}
		i++;
	}
	if (check_comp_isvalid(game) == FALSE)
		error_message("Invalid number of components\n");
}
