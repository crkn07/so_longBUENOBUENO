/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:55:32 by crtorres          #+#    #+#             */
/*   Updated: 2023/02/22 12:44:37 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

/**
 * 			col 0	col 1
 * row 0	[  ]	[  ]
 * row 1	[  ]	[  ]
 */
int	open_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		error_message("error opening file, check filename or file path\n");
	return (fd);
}

void	num_max_rowsandcols(t_game *game, int fd)
{
	int		tmp_cols;
	char	c;

	game->maps.rows = 0;
	game->maps.cols = 0;
	tmp_cols = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (game->maps.cols < tmp_cols)
			game->maps.cols = tmp_cols;
		if (c == '\n')
		{
			game->maps.rows++;
			tmp_cols = 0;
		}
		else
			tmp_cols++;
	}
}

void	alloc_map_mem(t_game *game, int fd)
{
	int	i;

	num_max_rowsandcols(game, fd);
	game->maps.coord = (char **)ft_calloc((game->maps.rows), sizeof(char *));
	i = 0;
	while (i < game->maps.rows)
	{
		game->maps.coord[i] = ft_calloc((game->maps.cols), sizeof(char));
		i++;
	}
}

/**
 * It reads the map file and stores the map in a 2D array
 * 
 * @param game the game struct
 * @param file the name of the file to be opened
 */
void	load_map(t_game *game, char *file)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	fd = open_fd(file);
	i = 0;
	while (i < game->maps.rows)
	{
		line = get_next_line(fd);
		if (map_rect(game, ft_strlen(line)) == FALSE)
			error_message("Not rectangular map, please check map file\n");
		j = -1;
		while (++j < game->maps.cols)
		{
			if (check_comp(line[j]) == TRUE)
				game->maps.coord[i][j] = line[j];
			else
				error_message("Invalid components in map.ber\n");
		}
		i++;
		free(line);
	}
	copymap(game);
	close(fd);
}

void	read_file(t_game *game, char *file)
{
	int	fd;

	check_extension(file, MAP_EXT);
	fd = open_fd(file);
	alloc_map_mem(game, fd);
	close(fd);
	load_map(game, file);
	if (fill_walled(game->maps) == FALSE)
		error_message("Map isn`t full walled!\n");
	if (valid_path_exit(game) == FALSE)
		error_message("it´s impossible to reach the exit");
	draw_comp_by_coord(game);
	ft_putstr_fd(BLUE"read_file completed\n"RESET, 1);
}
