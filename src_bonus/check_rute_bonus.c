/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rute_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:04:16 by crtorres          #+#    #+#             */
/*   Updated: 2023/02/18 11:42:38 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

/**
 * It checks if the player is around a box, and if so, it changes the box 
 * to a 'P' (player)
 * @param game the game struct
 * @param x the x coordinate of the player
 * @param y the y coordinate of the player
 */
void	aroundplayer(t_game *game, int x, int y)
{
	if (game->maps.mapcopy[x][y] == 'C' || game->maps.mapcopy[x][y] == '0')
		game->maps.mapcopy[x][y] = 'P';
}

/**
 * It checks if the player is next to the exit
 * 
 * @param game the game struct
 * 
 * @return the value of the last expression.
 */
int	reach_exit(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->maps.rows)
	{
		y = 0;
		while (y < game->maps.cols)
		{
			if ((game->maps.mapcopy[x][y] == 'E'
				&& game->maps.mapcopy[x][y + 1] == 'P')
				|| (game->maps.mapcopy[x][y] == 'E' &&
				game->maps.mapcopy[x][y - 1] == 'P')
				|| (game->maps.mapcopy[x][y] == 'E' &&
				game->maps.mapcopy[x - 1][y] == 'P')
				|| (game->maps.mapcopy[x][y] == 'E' &&
				game->maps.mapcopy[x + 1][y] == 'P'))
				return (TRUE);
			y++;
		}
		x++;
	}
	return (FALSE);
}

/**
 * It checks if the player is next to a box
 * 
 * @param game the game structure
 * @param x the x coordinate of the player
 * @param y the y coordinate of the player
 * 
 * @return 1 if the player is in the same position as a
 * 				box or a wall.
 */
int	checkplayer(t_game *game, int x, int y)
{
	if (game->maps.mapcopy[x][y] == 'P' &&
	(game->maps.mapcopy[x][y + 1] == 'C'
	|| game->maps.mapcopy[x][y + 1] == '0'
	|| game->maps.mapcopy[x - 1][y] == 'C'
	|| game->maps.mapcopy[x - 1][y] == '0'
	|| game->maps.mapcopy[x][y - 1] == 'C'
	|| game->maps.mapcopy[x][y - 1] == '0'
	|| game->maps.mapcopy[x + 1][y] == 'C'
	|| game->maps.mapcopy[x + 1][y] == '0'))
		return (TRUE);
	return (FALSE);
}

/**
 * It allocates memory for a copy of the map, and then copies the map into the
 * allocated memory
 * 
 * @param game the game struct
 * 
 * @return a boolean value.
 */
int	copymap(t_game *game)
{
	int	x;
	int	y;

	game->maps.mapcopy = (char **)ft_calloc(game->maps.rows, (sizeof(char *)));
	if (!game->maps.mapcopy)
		return (0);
	x = 0;
	while (x < game->maps.rows)
	{
		game->maps.mapcopy[x] = ft_calloc(game->maps.cols, sizeof(char));
		if (!game->maps.mapcopy)
			return (0);
		y = 0;
		while (y < game->maps.cols)
		{
			game->maps.mapcopy[x][y] = game->maps.coord[x][y];
			y++;
		}
		x++;
	}
	return (TRUE);
}

/**
 * It checks if the player can reach the exit
 * 
 * @param game the game struct
 * 
 * @return a boolean value.
 */
int	valid_path_exit(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->maps.rows)
	{
		y = 0;
		while (y < game->maps.cols)
		{
			if (checkplayer(game, x, y))
			{
				aroundplayer(game, x + 1, y);
				aroundplayer(game, x - 1, y);
				aroundplayer(game, x, y + 1);
				aroundplayer(game, x, y - 1);
				x = 0;
			}
			y++;
		}
		x++;
	}
	x = 0;
	while (x < game->maps.rows)
	{
		y = 0;
		while (y < game->maps.cols)
		{
			if (game->maps.mapcopy[x][y] == 'C')
				error_message("no collect");
			y++;
		}
		x++;
	}
	if (reach_exit(game))
		return (TRUE);
	return (FALSE);
}
