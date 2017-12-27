/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 17:09:04 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/27 17:44:56 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h" 

void    fractal_translate(t_env *env, int distance, char axis)
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
		*tmp_1 -= -distance / (env->cur_f->zoom_r * 10);
		*tmp_2 -= -distance / (env->cur_f->zoom_r * 10);
	}
	else
	{
		*tmp_1 += distance / (env->cur_f->zoom_r * 10);
		*tmp_2 += distance / (env->cur_f->zoom_r * 10);
	}
}

void	change_i(t_env *env, int i)
{
	if (i <= 0)
	{
		if (env->cur_f->i_max + i <= 0)
			env->cur_f->i_max = 0;
		else
			env->cur_f->i_max += i;
	}
	else
		env->cur_f->i_max += i;
}
