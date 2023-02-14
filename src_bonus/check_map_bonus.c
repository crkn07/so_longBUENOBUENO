/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 04:17:43 by jisokang          #+#    #+#             */
/*   Updated: 2023/02/13 23:11:55 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

/**
 * check map file components
 * 0 : an empty space.
 * 1 : a wall.
 * C : a Collectible.
 * E : map Exit.
 * P : the Player’s starting position.
 * R : team Rocket. enemy patrol.
 */
int	check_comp(char c)
{
	if (c == '0' || c == '1' || c == 'C'
		|| c == 'E' || c == 'P' || c == 'R')
		return (TRUE);
	return (FALSE);
}

int	map_rect(t_game *game, int len2)
{
	int	len1;

	len1 = game->maps.cols;
	if (len1 != len2)
		return (FALSE);
	return (TRUE);
}

int	fill_walled(t_map maps)
{
	int	max_col;
	int	max_row;
	int	i;

	i = 0;
	max_col = maps.cols - 1;
	max_row = maps.rows - 1;
	while (i < maps.rows)
	{
		if (maps.coord[i][0] != '1' || maps.coord[i][max_col] != '1')
			return (FALSE);
		i++;
	}
	i = 0;
	while (i < maps.cols)
	{
		if (maps.coord[0][i] != '1' || maps.coord[max_row][i] != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

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