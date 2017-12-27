/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 14:32:36 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/27 17:53:49 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		expose_hook(t_env *env)
{
	mlx_fractal(env);
	return (0);
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
	if (key == KEY_ENTER)
		change_color(env);
	if (key == KEY_LEFT)
		fractal_translate(env, 1, 'x');
	if (key == KEY_DOWN)
		fractal_translate(env, -1, 'y');
	if (key == KEY_RIGHT)
		fractal_translate(env, -1, 'x');
	if (key == KEY_UP)
		fractal_translate(env, 1, 'y');
	if (key == KEY_MINUS)
		change_i(env, -5);
	if (key == KEY_PLUS)
		change_i(env, 5);
	switch_fractal(key, env);
	mlx_fractal(env);
	return (0);
}
