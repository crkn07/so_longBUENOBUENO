/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:14:15 by jisokang          #+#    #+#             */
/*   Updated: 2023/02/19 10:40:20 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H

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
int		valid_path_exit(t_game *game);
int		copymap(t_game *game);
int		open_fd(char *file);
void	error_message(char *msg);
void	exit_message(char *msg, t_game *game);

#endif
