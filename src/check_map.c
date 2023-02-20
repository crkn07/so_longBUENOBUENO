/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 04:17:43 by jisokang          #+#    #+#             */
/*   Updated: 2023/02/18 11:33:18 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * check map file components
 * 0 : an empty space.
 * 1 : a wall.
 * C : a Collectible.
 * E : map Exit.
 * P : the Player’s starting position.
 * R : Charizard. enemy patrol.
 */
int	check_comp(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' || c == 'R')
		return (TRUE);
	return (FALSE);
}

/**
 * It checks if the number of columns in the map is equal to the 
 * number of columns in the first line of the map
 * 
 * @param game the game struct
 * @param len2 The length of the current line in the map file.
 * 
 * @return a boolean value.
 */
int	map_rect(t_game *game, int len2)
{
	int	len1;

	len1 = game->maps.cols;
	if (len1 != len2)
		return (FALSE);
	return (TRUE);
}

/**
 * It checks if the first and last columns and rows of the map are all walls
 * @param map The map structure.
 * @return a boolean value.
 */
int	fill_walled(t_map map)
{
	int	max_col;
	int	max_row;
	int	i;

	i = 0;
	max_col = map.cols - 1;
	max_row = map.rows - 1;
	while (i < map.rows)
	{
		if (map.coord[i][0] != '1' || map.coord[i][max_col] != '1')
			return (FALSE);
		i++;
	}
	i = 0;
	while (i < map.cols)
	{
		if (map.coord[0][i] != '1' || map.coord[max_row][i] != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/**
 * It checks if the sprite can move in the direction it's facing
 * @param game the game struct
 * @param sprite the sprite that is moving
 * @param dir the direction the sprite is moving in
 * @return TRUE or FALSE
 */
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

/**
 * It checks if the extension of the file is valid
 * @param str the string to check
 * @param ext The extension to check for.
 * @return TRUE
 */
int	check_extension(char *str, char *ext)
{
	int	i;
	int	j;

	if (ext[0] != '.')
		error_message("map ext[0] mut be a dot\n");
	i = ft_strlen(str) - ft_strlen(ext);
	if (i <= 0 || str[i] != '.')
		error_message("invalid extension\n");
	j = 0;
	while (str[i + j] != '\0' && ext[j] != '\0')
	{
		if (str[i + j] == ext[j])
			j++;
		else
			break ;
	}
	if (!(str[i + j] == '\0' && ext[j] == '\0'))
		error_message("invalid extension\n");
	return (TRUE);
}
