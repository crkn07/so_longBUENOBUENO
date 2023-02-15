/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:14:15 by jisokang          #+#    #+#             */
/*   Updated: 2023/02/14 18:39:07 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

/**
 * [Component]
 * The component is an element that contains map file.
 * 'p' : player
 * 'e' : exit
 * 'c' : collectible item
 * 'r' : Team Rocket (enemy)
 *  */
typedef struct s_compo
{
	int		p;
	int		e;
	int		c;
	int		r;
}			t_compo;

typedef struct s_map
{
	int		rows;
	int		cols;
	char	**coord;
	char	**mapcopy;
	char	*file;
	t_compo	cnt;
}			t_map;

# define MAP_EXT		".ber"

# define TILE_SIZE		64

typedef struct s_game	t_game;

int		check_extension(char *str, char *ext);
int		check_comp(char c);
int		map_rect(t_game *game, int len2);
int		fill_walled(t_map maps);
void	count_max_rows_cols(t_game *game, int fd);
void	map_malloc(t_game *game, int fd);
int		open_file(char *filename);
void	map_load(t_game *game, char *filename);
void	draw_comp_by_coord(t_game *game);
void	file_read(t_game *game, char *filename);
int		path_ok(t_game *game);
int		mapcopy(t_game *game);

#endif
