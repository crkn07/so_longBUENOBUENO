/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:18:05 by crtorres          #+#    #+#             */
/*   Updated: 2023/02/27 12:42:10 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

/*------------------------------
 * GAME MODE OPTION
 *------------------------------*/
/* 1 : BONUS MODE
 * 0 : MANDATORY MODE */
# define GAME_MODE		0

/*------------------------------
 * ASSET PATH
 *------------------------------*/
# define ASSET_PATH		"./textures/"

/*------------------------------
 * COMPO OPTION
 *------------------------------*/
# define COMPO_P_MAX	1
# define COMPO_C_MAX	1
# define COMPO_E_MAX	1

/*------------------------------
 * PLAYER OPTION
 *------------------------------*/
/* Player Speed
 * Default	: 4
 * Min		: 1
 * Max		: 64
 * Enter only multiples of 2. */
# define PLAYER_SPEED	4
# define ENEMY_SPEED	8

/*------------------------------
 * KEYBOARD SETTINGS
 *------------------------------*/
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

//===SETTINGS COLORS===/
//===Color font code===/
# define BLACK   "\x1B[30m"
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define WHITE   "\x1B[37m"
# define ORANGE  "\x1B[38;2;255;128;0m"
# define ROSE    "\x1B[38;2;255;151;203m"
# define LBLUE   "\x1B[38;2;53;149;240m"
# define LGREEN  "\x1B[38;2;17;245;120m"
# define GRAY    "\x1B[38;2;176;174;174m"
//===Color background code===/
# define BG_BLACK   "\x1B[40m"
# define BG_RED     "\x1B[41m"
# define BG_GREEN   "\x1B[42m"
# define BG_YELLOW  "\x1B[43m"
# define BG_BLUE    "\x1B[44m"
# define BG_MAGENTA "\x1B[45m"
# define BG_CYAN    "\x1B[46m"
# define BG_WHITE   "\x1B[47m"
# define BG_ORANGE  "\x1B[48;2;255;128;0m"
# define BG_LBLUE   "\x1B[48;2;53;149;240m"
# define BG_LGREEN  "\x1B[48;2;17;245;120m"
# define BG_GRAY    "\x1B[48;2;176;174;174m"
# define BG_ROSE    "\x1B[48;2;255;151;203m"

# define RESET   "\x1b[0m"

typedef struct s_game	t_game;

int		keypress(int keycode, t_game *game);

#endif
