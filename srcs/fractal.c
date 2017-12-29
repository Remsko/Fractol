/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:52:22 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/29 13:52:28 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		fractal_mandelbrot(t_env *env, t_fractal f, t_pos *pos)
{
	f.c.r = 1.0 * (pos->x - env->win_w / 2)
		/ (0.5 * f.zoom_r * env->win_w) + f.x1;
	f.c.i = 1.0 * (pos->y - env->win_h / 2)
		/ (0.5 * f.zoom_r * env->win_h) + f.y1;
	while (((f.z.r * f.z.r + f.z.i * f.z.i) < 4) && (f.i < f.i_max))
	{
		f.tmp = f.z.r;
		f.z.r = (f.z.r * f.z.r) - (f.z.i * f.z.i) + f.c.r;
		f.z.i = 2 * f.z.i * f.tmp + f.c.i;
		f.i++;
	}
	if (f.i == f.i_max)
		return (get_color(100, *(env->cur_color)));
	return (get_color(f.i * f.i * 0.1, *(env->cur_color)));
}

int		fractal_julia(t_env *env, t_fractal f, t_pos *pos)
{
	f.z.r = 1.0 * (pos->x - env->win_w / 2)
		/ (0.5 * f.zoom_r * env->win_w) + f.x1;
	f.z.i = (pos->y - env->win_h / 2)
		/ (0.5 * f.zoom_r * env->win_h) + f.y1;
	while (((f.z.r * f.z.r) + (f.z.i * f.z.i) < 4) &&
			(f.i < f.i_max))
	{
		f.tmp = f.z.r;
		f.z.r = (f.z.r * f.z.r) - (f.z.i * f.z.i) + f.c.r;
		f.z.i = 2 * f.z.i * f.tmp + f.c.i;
		f.i++;
	}
	if (f.i == f.i_max)
		return (get_color(100, *(env->cur_color)));
	return (get_color(f.i * f.i * 0.1, *(env->cur_color)));
}

int		fractal_mandelbar(t_env *env, t_fractal f, t_pos *pos)
{
	f.c.r = 1.0 * (pos->x - env->win_w / 2)
		/ (0.5 * f.zoom_r * env->win_w) + f.x1;
	f.c.i = (pos->y - env->win_h / 2)
		/ (0.5 * f.zoom_r * env->win_h) + f.y1;
	while (((f.z.r * f.z.r) + (f.z.i * f.z.i) < 4) && (f.i < f.i_max))
	{
		f.tmp = f.z.r;
		f.z.i *= -1;
		f.z.r = f.z.r * f.z.r - f.z.i * f.z.i
			+ f.c.r;
		f.z.i = 2 * f.z.i * f.tmp + f.c.i;
		f.i++;
	}
	if (f.i == f.i_max)
		return (get_color(100, *(env->cur_color)));
	return (get_color(f.i * f.i * 0.1, *(env->cur_color)));
}

int		fractal_burningship(t_env *env, t_fractal f, t_pos *pos)
{
	f.c.r = 1.0 * (pos->x - env->win_w / 2)
		/ (0.5 * f.zoom_r * env->win_w) + f.x1;
	f.c.i = (pos->y - env->win_h / 2)
		/ (0.5 * f.zoom_r * env->win_h) + f.y1;
	while (((f.z.r * f.z.r + f.z.i * f.z.i) < 4) && (f.i < f.i_max))
	{
		f.tmp = f.z.r;
		f.z.r = f.z.r * f.z.r - f.z.i * f.z.i - f.c.r;
		f.z.i = 2 * fabs(f.z.i) * fabs(f.tmp) + f.c.i;
		f.i++;
	}
	if (f.i == f.i_max)
		return (get_color(100, *(env->cur_color)));
	return (get_color(f.i * f.i * 0.1, *(env->cur_color)));
}
