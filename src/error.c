/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 00:54:34 by crtorres          #+#    #+#             */
/*   Updated: 2023/02/21 15:12:36 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_message(char *msg)
{
	ft_putstr_fd(RED "-*-*-*-*-*-*-*-*-*-*-\n\n" RESET, 2);
	ft_putstr_fd(BG_RED, 2);
	ft_putstr_fd("Error", 2);
	ft_putstr_fd(RESET, 2);
	ft_putstr_fd("\n\n", 2);
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("-*-*-*-*-*-*-*-*-*-*-*-*-\n", 2);
	ft_putstr_fd(RESET, 2);
	exit (EXIT_FAILURE);
}

void	exit_message(char *msg, t_game *game)
{
	ft_putstr_fd(ORANGE "-*-*-*-*-*-*-\n" RESET, 2);
	ft_putstr_fd(BG_ORANGE, 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(RESET, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd(ORANGE "-*-*-*-*-*-*-\n" RESET, 2);
	close_game(game);
}
