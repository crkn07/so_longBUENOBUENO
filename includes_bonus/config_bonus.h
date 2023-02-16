/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:18:05 by jisokang          #+#    #+#             */
/*   Updated: 2023/02/13 22:59:36 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_BONUS_H
# define CONFIG_BONUS_H

/*------------------------------
 * GAME MODE OPTION
 *------------------------------*/
/* 1 : BONUS MODE
 * 0 : MANDATORY MODE */
# define GAME_MODE		1

/*------------------------------
 * ASSET PATH
 *------------------------------*/
# define ASSET_PATH		"./asset/"

/*------------------------------
 * COMPO OPTION
 *------------------------------*/
# define COMPO_P_MAX	1
# define COMPO_C_MAX	1
# define COMPO_E_MAX	1
# define COMPO_R_MAX	1

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

#endif
