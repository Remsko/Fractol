/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 12:12:13 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/26 13:31:21 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_color(t_env *env)
{
	env->color = (t_color*)malloc(sizeof(t_color) * 4);
	env->color[0] = (t_color){0xFF9999, 0xFFCC99, 0xFFFF99, 0xCCFF99, 0x99FF99, 0x99FFCC, 0x99FFFF, 0x99CCFF, 0x999FF, 0xCC99FF, 0xFF99FF, 0xFF99CC}; // 12 colors to choose
//	env->color[1] = {};
//	env->color[2] = {};
//	env->color[3] = {};
	env->cur_color = &(env->color[0]);
	env->i_color = 0;
}

int		get_color(int z, t_color color)
{
	z = sin(z) * 100;
	if (z < 0)
		color.c = color.c_0;
	else if (z >= 0 && z < 10)
		color.c = color.c_1;
	else if (z >= 10 && z < 20)
		color.c = color.c_2;
	else if (z >= 20 && z < 30)
		color.c = color.c_3;
	else if (z >= 30 && z < 40)
		color.c = color.c_4;
	else if (z >= 40 && z < 50)
		color.c = color.c_5;
	else if (z >= 50 && z < 60)
		color.c = color.c_6;
	else if (z >= 60 && z < 70)
		color.c = color.c_7;
	else if (z >= 70 && z < 80)
		color.c = color.c_8;
	else if (z >= 80 && z < 90)
		color.c = color.c_9;
	else if (z >= 90)
		color.c = color.c_10;
	return (color.c);
}

void	change_color(t_env *env)
{
	if (env->i_color == COLOR_NB - 1)
		env->i_color = 0;
	else
		env->i_color++;
	env->cur_color = &(env->color[env->i_color]);
}
