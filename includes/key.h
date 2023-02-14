/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 02:27:06 by jisokang          #+#    #+#             */
/*   Updated: 2023/02/14 00:12:37 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# define KEY_PRESS		2

/* Clicking on the RED cross on the window frame */
# define KEY_EXIT		17

# define KEY_ESC			53
# define KEY_RESET			15
# define KEY_RETURN			36

# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_UP				126
# define KEY_LEFT			123
# define KEY_DOWN			125
# define KEY_RIGHT			124

typedef struct s_game	t_game;

int		keypress(int keycode, t_game *game);

#endif
