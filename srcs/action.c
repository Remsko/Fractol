/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 17:09:04 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/29 13:36:33 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fractal_translate(t_env *env, int distance, char axis)
{
	double *tmp_1;
	double *tmp_2;

	if (axis == 'x')
	{
		tmp_1 = &env->cur_f->x1;
		tmp_2 = &env->cur_f->x2;
	}
	else
	{
		tmp_1 = &env->cur_f->y1;
		tmp_2 = &env->cur_f->y2;
	}
	if (distance < 0)
	{
		*tmp_1 -= -distance / (env->cur_f->zoom_r * 20);
		*tmp_2 -= -distance / (env->cur_f->zoom_r * 20);
	}
	else
	{
		*tmp_1 += distance / (env->cur_f->zoom_r * 20);
		*tmp_2 += distance / (env->cur_f->zoom_r * 20);
	}
}

void	change_i(t_env *env, int i)
{
	if (i <= 0)
	{
		if (env->cur_f->i_max + i <= 0)
			env->cur_f->i_max = 3;
		else
			env->cur_f->i_max += i;
	}
	else
		env->cur_f->i_max += i;
}

int		mouse_hook(int key, int x, int y, t_env *env)
{
	if (key == LEFT_CLICK || key == SCROLL_UP || key == RIGHT_CLICK ||
			key == SCROLL_DOWN || key == PAD_PLUS || key == PAD_MINUS)
	{
		env->cur_f->x1 += ((((double)x - env->win_h / 2) / env->win_w / 2)
				/ env->cur_f->zoom_r * 10) / 3;
		env->cur_f->x2 += ((((double)x - env->win_h / 2) / env->win_w / 2)
				/ env->cur_f->zoom_r * 10) / 3;
		env->cur_f->y1 += ((((double)y - env->win_w / 2) / env->win_h / 2)
				/ env->cur_f->zoom_r * 10) / 3;
		env->cur_f->y2 += ((((double)y - env->win_w / 2) / env->win_h / 2)
				/ env->cur_f->zoom_r * 10) / 3;
		if (key == RIGHT_CLICK || key == SCROLL_DOWN || key == PAD_PLUS)
			env->cur_f->zoom_r *= 1.1;
		else if (key == LEFT_CLICK || key == SCROLL_UP || key == PAD_MINUS)
			env->cur_f->zoom_r /= 1.1;
	}
	mlx_fractal(env);
	return (0);
}

int		motion_hook(int x, int y, t_env *env)
{
	if (x >= 0 && y >= 0 && x <= (int)env->win_w && y <= (int)env->win_h
			&& env->active_m == 'Y')
	{
		env->cur_f->c.r = (double)x / (double)env->win_w * 4 - 2;
		env->cur_f->c.i = (double)y / (double)env->win_h * 4 - 2;
		mlx_fractal(env);
	}
	return (0);
}
