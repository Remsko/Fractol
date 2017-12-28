/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 14:32:36 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/28 14:52:04 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		expose_hook(t_env *env)
{
	mlx_fractal(env);
	return (0);
}

void    simple_zoom(t_env *env, double zoom_ratio)
{
	if (zoom_ratio >= 0.0)
		env->cur_f->zoom_r *= zoom_ratio;
	else
		env->cur_f->zoom_r /= -zoom_ratio;
	zoom_ratio = env->cur_f->zoom_r;
	env->cur_f->x1 += ((env->win_h / 2) / env->win_w / 2)
		/ zoom_ratio * 10;
	env->cur_f->x2 += ((env->win_h / 2) / env->win_w / 2)
		/ zoom_ratio * 10;
	env->cur_f->y1 += ((env->win_w / 2) / env->win_h / 2)
		/ zoom_ratio * 10;
	env->cur_f->y2 += ((env->win_w / 2) / env->win_h / 2)
		/ zoom_ratio * 10;
}

void    switch_fractal(int key, t_env *env)
{
	if (key == KEY_1)
		env->cur_f = &env->f[0];
	else if (key == KEY_2)
		env->cur_f = &env->f[1];
	else if (key == KEY_3)
		env->cur_f = &env->f[2];
	else if (key == KEY_4)
		env->cur_f = &env->f[3];
}

int		key_hook(int key, t_env *env)
{
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(EXIT_SUCCESS);
	}
	if (key == PAD_PLUS)
		simple_zoom(env, 1.1);
	if (key == PAD_MINUS)
		simple_zoom(env, -1.1);
	if (key == KEY_ENTER)
		change_color(env);
	if (key == KEY_LEFT)
		fractal_translate(env, 5, 'x');
	if (key == KEY_DOWN)
		fractal_translate(env, -5, 'y');
	if (key == KEY_RIGHT)
		fractal_translate(env, -5, 'x');
	if (key == KEY_UP)
		fractal_translate(env, 5, 'y');
	if (key == KEY_MINUS)
		change_i(env, -5);
	if (key == KEY_PLUS)
		change_i(env, 5);
	if (key == KEY_SPACE)
		env->active_m = env->active_m == 'Y' ? 'N' : 'Y';
	switch_fractal(key, env);
	mlx_fractal(env);
	return (0);
}
