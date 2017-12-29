/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 12:12:13 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/29 13:45:34 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_color(t_env *env)
{
	env->color = (t_color*)malloc(sizeof(t_color) * 6);
	env->color[0] = (t_color){0xFF9999, 0xFFCC99, 0xFFFF99, 0xCCFF99, 0x99FF99,
		0x99FFCC, 0x99FFFF, 0x99CCFF, 0x999FF, 0xCC99FF, 0xFF99FF, 0xFF99CC};
	env->color[1] = (t_color){0x330019, 0x660033, 0x99004C, 0xCC0066, 0xFF007F,
		0xFF3399, 0xFF66B2, 0xFF99CC, 0xFFCCE5, 0xCCCCFF, 0xE0E0E0, 0xFFFFFF};
	env->color[2] = (t_color){0x0E6251, 0x117864, 0x148F77, 0x17A589, 0x1ABC9C,
		0x48C9B0, 0x76D7C4, 0xA3E4D7, 0xE8F8F5, 0x17202A, 0xF9EBEA, 0xD6EAF8};
	env->color[3] = (t_color){0x000000, 0x202020, 0x404040, 0x606060, 0x808080,
		0xA0A0A0, 0xC0C0C0, 0xE0E0E0, 0xFFFFFF, 0xFFFF00, 0xE628AB, 0xE9890C};
	env->color[4] = (t_color){0xFFFFFF, 0x000000, 0x001933, 0x003366, 0x004C99,
		0x0066CC, 0x0080FF, 0x3399FF, 0x66B2FF, 0x99CCFF, 0xCCE5FF, 0xFFCCFF};
	env->color[5] = (t_color){0x000000, 0x111111, 0x222222, 0x333333, 0x444444,
		0x555555, 0x666666, 0x777777, 0x888888, 0x999999, 0xAAAAAA, 0xBBBBBB};
	env->cur_color = &(env->color[0]);
	env->i_color = 0;
}

int		get_color(int z, t_color color)
{
	z = sin(z) * 100;
	color.c = 0xD6EAF8;
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
	else if (z >= 90 && z < 100)
		color.c = color.c_10;
	return (color.c);
}

void	change_color(t_env *env)
{
	if (env->i_color == 5)
		env->i_color = 0;
	else
		env->i_color++;
	env->cur_color = &(env->color[env->i_color]);
}
