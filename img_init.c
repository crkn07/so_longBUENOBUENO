/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 07:18:32 by jisokang          #+#    #+#             */
/*   Updated: 2023/02/13 23:42:03 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

static void	rest_imgmap_init(t_game *game)
{
	game->tile.t0.ptr = ft_xpm_to_img(game, "grass64x64.xpm");
	game->tile.t1.ptr = ft_xpm_to_img(game, "tree64x64.xpm");
	game->tile.tl.ptr = ft_xpm_to_img(game, "ladder64x64.xpm");
	game->tile.tb.ptr = ft_xpm_to_img(game, "nintendocounter1.xpm");
	game->tile.ts.ptr = ft_xpm_to_img(game, "Ditto64x64.xpm");
}

static void	imgplayer_init(t_game *game)
{
	t_spr	*ply;

	ply = &(game->player.spr);
	ply->imgx[DIR_NORTH][0].ptr = ft_xpm_to_img(game, "char_back.xpm");
	ply->imgx[DIR_NORTH][1].ptr = ft_xpm_to_img(game, "char_back1.xpm");
	ply->imgx[DIR_NORTH][2].ptr = ft_xpm_to_img(game, "char_back2.xpm");
	ply->imgx[DIR_SOUTH][0].ptr = ft_xpm_to_img(game, "char_front.xpm");
	ply->imgx[DIR_SOUTH][1].ptr = ft_xpm_to_img(game, "char_front1.xpm");
	ply->imgx[DIR_SOUTH][2].ptr = ft_xpm_to_img(game, "char_front2.xpm");
	ply->imgx[DIR_WEST][0].ptr = ft_xpm_to_img(game, "char_left.xpm");
	ply->imgx[DIR_WEST][1].ptr = ft_xpm_to_img(game, "char_left1.xpm");
	ply->imgx[DIR_WEST][2].ptr = ft_xpm_to_img(game, "char_left2.xpm");
	ply->imgx[DIR_EAST][0].ptr = ft_xpm_to_img(game, "char_right.xpm");
	ply->imgx[DIR_EAST][1].ptr = ft_xpm_to_img(game, "char_right1.xpm");
	ply->imgx[DIR_EAST][2].ptr = ft_xpm_to_img(game, "char_right2.xpm");
}

static void	imgenemy_init(t_game *game)
{
	game->enemy.imgx[DIR_NORTH][0].ptr = ft_xpm_to_img(game, "enemyback.xpm");
	game->enemy.imgx[DIR_SOUTH][0].ptr = ft_xpm_to_img(game, "enemyfront.xpm");
	game->enemy.imgx[DIR_WEST][0].ptr = ft_xpm_to_img(game, "enemyleft.xpm");
	game->enemy.imgx[DIR_EAST][0].ptr = ft_xpm_to_img(game, "enemyright.xpm");
}

static void	init_rest_ofimg(t_game *game)
{
	game->opening.ptr = ft_xpm_to_img(game, "opening.xpm");
	game->gameover.ptr = ft_xpm_to_img(game, "gameover.xpm");
	game->ending.ptr = ft_xpm_to_img(game, "ending.xpm");
	game->collec.ball.ptr = ft_xpm_to_img(game, "ball.xpm");
}

void	init_img(t_game *game)
{
	rest_imgmap_init(game);
	imgplayer_init(game);
	imgenemy_init(game);
	init_rest_ofimg(game);
}
