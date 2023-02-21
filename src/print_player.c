/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:09:00 by crtorres          #+#    #+#             */
/*   Updated: 2023/02/21 15:23:07 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * It returns the sprite to be drawn for the player, depending on the 
 * direction and the frame
 * 
 * @param game the game struct
 * @param dir the direction the player is facing
 * 
 * @return A pointer to a t_img struct.
 */
static t_img	*get_spr_player(t_game *game, int dir)
{
	t_img	*spr;

	if (game->player.spr.frame == 1)
		spr = &(game->player.spr.imgx[dir][1]);
	else if (game->player.spr.frame == 3)
		spr = &(game->player.spr.imgx[dir][2]);
	else
		spr = &(game->player.spr.imgx[dir][0]);
	return (spr);
}

/**
 * It prints the player's sprite
 * at the correct location, and increments the player's position
 * 
 * @param game the game struct
 * @param player the player's sprite
 * @param sprite the sprite to be printed
 * @param dir the direction the player is walking in
 */
static
void	print_player_walk(t_game *game, t_spr *player, t_img *sprite, int dir)
{
	int	x;
	int	y;

	game->flag.held_keys = TRUE;
	x = (player->x0 * TILE_SIZE)
		+ (game->dir2coord[dir].x * player->i * player->move);
	y = ((player->y0 - 1) * TILE_SIZE)
		+ (game->dir2coord[dir].y * player->i * player->move);
	ft_put_img(game, sprite->ptr, x, y);
	player->i += PLAYER_SPEED;
	if (player->i >= 64)
	{
		player->i = 0;
		game->player.spr.frame++;
		game->flag.held_keys = FALSE;
		game->flag.player_walk = FALSE;
	}
}

void	print_player(t_game *game)
{
	int		dir;
	t_spr	*player;
	t_img	*sprite;

	dir = game->player.spr.dir;
	player = &(game->player.spr);
	sprite = get_spr_player(game, dir);
	if (game->flag.player_walk)
		print_player_walk(game, player, sprite, dir);
	else
		ft_put_img64(game, sprite->ptr, player->x, player->y - 1);
}
