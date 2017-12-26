/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:52:22 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/26 13:19:39 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		fractal_mandelbrot(t_env *env, t_fractal *f, t_pos *pos)
{
	f->c.r = (pos->x - WIN_W / 2.0) / (0.5 * f->zoom_r * WIN_H) + f->pos1.x;
	f->c.i = (pos->y - WIN_H / 2.0) / (0.5 * f->zoom_r * WIN_H) + + f->pos1.y;
	while ((f->z.r * f->z.r + f->z.i) < 4 && f->i < f->i_max)
	{
		f->tmp = f->z.r;
		f->z.r = (f->z.r * f->z.r) - (f->z.i * f->z.i) + f->c.r;
		f->z.i = 2 * f->z.i * f->tmp + f->c.i;
		f->i++;
	}
	if (f->i == f->i_max)
		return (get_color(100, *(env->cur_color)));
	return (get_color((f->i * f->i) * 0.1, *(env->cur_color)));
}
