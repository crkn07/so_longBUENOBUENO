/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:51:09 by jisokang          #+#    #+#             */
/*   Updated: 2023/02/16 17:57:34 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# include "color.h"
# include "key.h"
# include "error.h"
# include "map.h"
# include "config.h"
# include "../mlx/mlx.h"
# include "../Libft/libft.h"

/* Game mode */
# define MANDATORY		0
# define BONUS			1

# define TRUE			1
# define FALSE			0

# define DIR_NONE		0
# define DIR_SOUTH		1
# define DIR_WEST		2
# define DIR_NORTH		3
# define DIR_EAST		4

/* Game Scene Status */
# define GAME_START		0
# define GAME_INITIATED	1
# define GAME_OVER		2
# define GAME_ENDING	3

/* Player */
# define P_MAX_FRAME	3

typedef struct s_map	t_map;

typedef struct s_coord
{
	int		x;
	int		y;
}			t_coord;

typedef struct s_clst
{
	t_coord			coord;
	int				istouch;
	struct s_clst	*next;
}					t_clst;

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		h;
	int		w;
}			t_img;

typedef struct s_tile
{
	t_img	t0;
	t_img	t1;
	t_img	tl;
	t_img	tb;
	t_img	ts;
}			t_tile;

typedef struct s_spr
{
	t_img	imgx[5][3];
	int		frame;
	int		frame_max;
	int		step;
	int		x;
	int		y;
	int		x0;
	int		y0;
	int		i;
	int		dir;
	int		move;
}			t_spr;

typedef struct s_coll
{
	t_img	ball;
	t_clst	*clst;
}			t_coll;

typedef struct s_player
{
	t_spr	spr;
	int		death;
	int		step;
	int		item;
}			t_player;

typedef struct s_flags
{
	int		collect_all;
	int		held_keys;
	int		player_walk;
	int		enemy_walk;
	int		step_cnt;
	int		game_scene;
}			t_flags;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			fps;
	t_img		img64;
	t_img		opening;
	t_img		gameover;
	t_img		ending;
	t_tile		tile;
	t_coll		collec;
	t_player	player;
	t_spr		enemy;
	t_coord		dir2coord[5];
	t_map		maps;
	t_flags		 flag;
}				t_game;

void	*ft_xpm_to_img(t_game *game, char *str);
void	ft_put_img64(t_game *game, void *img_ptr, int x, int y);
void	ft_put_img(t_game *game, void *img_ptr, int x, int y);

void	init_collectable(t_game *game);
void	print_collectable(t_game *game);

void	launch_player(t_game *game);
void	init_flags(t_game *game);
void	launch_game(t_game *game);
int		reset_game(t_game *game);

void	init_dir(t_game *game);
void	dir_to_coord(int dir, int *x, int *y);
int		check_collision(t_game *game, t_spr *sprite, int dir);
void	move_north(t_game *game, t_spr *sprite);
void	move_south(t_game *game, t_spr *sprite);
void	move_west(t_game *game, t_spr *sprite);
void	move_east(t_game *game, t_spr *sprite);

t_clst	*clst_new(int x, int y);
t_clst	*clst_last(t_clst *lst);

void	clst_add_back(t_clst **lst, t_clst *new);
void	clst_clear(t_clst *head);

void	print_map(t_game *game);
void	init_img(t_game *game);
void	print_player(t_game *game);
void	print_enemy(t_game *game);
void	draw_step_count(t_game *game);
void	print_covers_change(t_game *game);

void	moments_tester(t_game *game);
void	enemy_behaviour(t_game *game);
void	draw_sprites(t_game *game);
void	init_enemy(t_game *game);

void	move_dir(t_game *game, t_spr *sprite, int dir);
void	spin_like_clock(t_spr *sprite);

void	launch_window(t_game *game);
int		close_game(t_game *game);

void	read_file(t_game *game, char *file);

#endif
