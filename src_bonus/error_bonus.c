/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:54:34 by jisokang          #+#    #+#             */
/*   Updated: 2023/02/13 23:25:17 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	error_message(char *msg)
{
	ft_putstr_fd(RED "Error\n" RESET, 2);
	ft_putstr_fd(YELLOW, 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(RESET, 2);
	exit (EXIT_FAILURE);
}
