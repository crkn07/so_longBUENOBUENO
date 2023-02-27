/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smaller_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:47:08 by crtorres          #+#    #+#             */
/*   Updated: 2023/02/22 15:37:47 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_xpm_to_img(t_game *game, char *str)
{
	char	*path;
	void	*img;

	path = ft_strjoin(ASSET_PATH, str);
	img = mlx_xpm_file_to_image(game->mlx, path,
			&(game->img64.w), &(game->img64.h));
	free(path);
	if (img == NULL)
		error_message("XPM to image fail! please check it.\n");
	return (img);
}

void	ft_put_img64(t_game *game, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		img_ptr, x * TILE_SIZE, y * TILE_SIZE);
}

void	ft_put_img(t_game *game, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img_ptr, x, y);
}
