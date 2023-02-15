/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:37:55 by jisokang          #+#    #+#             */
/*   Updated: 2023/02/15 12:58:34 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

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
		error_message("error opening file\n");
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
		/* Checking if the current number of columns is less than the previous number of
		columns. If it is, then it is updating the number of columns. */
		if (game->maps.cols < tmp_cols)
			game->maps.cols = tmp_cols;
		/* Checking if the current character is a new line. If it is, then it is updating
		the number of rows and resetting the number of columns. */
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
	game->maps.coord = (char **)malloc(sizeof(char *) * (game->maps.rows));
	i = 0;
	while (i < game->maps.rows)	/* Checking if the current row is less than the total number of rows. */
	{
		game->maps.coord[i] = (char *)malloc(sizeof(char) * (game->maps.cols));
		i++;
	}
}



void	load_map(t_game *game, char *file)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	fd = open_fd(file);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (map_rect(game, ft_strlen(line)) == FALSE)
			error_message("Not rectangular map, please check map file\n");
		j = 0;
		while (j < game->maps.cols)
		{
			if  (check_comp(line[j]) == TRUE)
				game->maps.coord[i][j] = line[j];
			else
				error_message("Invalid components in map.ber\n");
			j++;
		}
		i++;
		free(line);
	}
	mapcopy(game);
	free(line);
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
	if (path_ok(game) == FALSE)
		error_message("no se puede");
	draw_comp_by_coord(game);
	ft_putstr_fd(BLUE"read_file completed\n"RESET, 1);
}