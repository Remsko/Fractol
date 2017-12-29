/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:17:20 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/29 13:48:37 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fractal(t_env *env)
{
	env->f = (t_fractal*)malloc(sizeof(t_fractal) * 5);
	env->f[0] = (t_fractal){{0, 0}, {0, 0}, -0.9, 0, 0, 0, env->win_w
		/ (0.6 + 2.1), env->win_h / (1.2 + 1.2), 0.5, 0, 0, 50,
			fractal_mandelbrot, ft_strdup("mandelbrot")};
	env->f[1] = (t_fractal){{0.285, 0.01}, {0, 0}, 0, 0, 0, 0, env->win_w
		/ (1.5 + 1.5), env->win_h / (1.2 + 1.2), 0.5, 0, 0, 50,
			fractal_julia, ft_strdup("julia")};
	env->f[2] = (t_fractal){{0, 0}, {0, 0}, 0, 0, 0, 0, env->win_w
		/ (1.5 + 1.1), env->win_h / (1.2 + 1.2), 0.5, 0, 0, 50,
			fractal_mandelbar, ft_strdup("mandelbar")};
	env->f[3] = (t_fractal){{0, 0}, {0, 0}, 0, 0, 0, 0, env->win_w
		/ (1.6 + 1.1), env->win_h / (1.7 + 0.7), 0.5, 0, 0, 50,
			fractal_burningship, ft_strdup("burningship")};
	env->cur_f = &env->f[0];
}

void	use_fractal(t_env *env, char *name)
{
	if (ft_strcmp(name, "mandelbrot") == 0)
		env->cur_f = &(env->f[0]);
	if (ft_strcmp(name, "julia") == 0)
		env->cur_f = &(env->f[1]);
	if (ft_strcmp(name, "mandelbar") == 0)
		env->cur_f = &(env->f[2]);
	if (ft_strcmp(name, "burningship") == 0)
		env->cur_f = &(env->f[3]);
}
