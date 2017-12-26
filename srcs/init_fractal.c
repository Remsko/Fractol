/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:17:20 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/26 13:11:49 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fractal(t_env *env)
{
	env->f = (t_fractal*)malloc(sizeof(t_fractal) * 5);
	env->f[0] = (t_fractal){{0, 0}, {0, 0}, {-0.9, 0}, {0, 0}, {WIN_W / (0.6 + 2.1), WIN_H / (1.2 + 1.2)}, 0.5, 0, 0, 50, fractal_mandelbrot, ft_strdup("mandelbrot")};
}

void	use_fractal(t_env *env, char *name)
{
	if (ft_strcmp(name, "mandelbrot") == 0)
		env->cur_f = &(env->f[0]);
	else
		env->cur_f = &(env->f[0]);
}
