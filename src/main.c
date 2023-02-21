/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 23:09:34 by crtorres          #+#    #+#             */
/*   Updated: 2023/02/21 15:07:54 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	frame_cunt(t_game *game)
{
	game->fps++;
	if (game->fps >= 600)
		game->fps = 0;
}

int	main_loop(t_game *game)
{
	if (game->flag.game_scene != GAME_INITIATED)
		print_covers_change(game);
	else
	{
		print_map(game);
		print_collectable(game);
		moments_tester(game);
		enemy_behaviour(game);
		draw_sprites(game);
		draw_step_count(game);
	}
	frame_cunt(game);
	return (0);
}

/* void	ft_leaks()
{
	system("leaks so_long");
		atexit(ft_leaks);
} */

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_message("map file still to be added\n");
	init_collectable(&game);
	read_file(&game, argv[1]);
	launch_game(&game);
	mlx_hook(game.win, KEY_PRESS, 0, &keypress, &game);
	mlx_hook(game.win, KEY_EXIT, 0, &close_game, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
}
