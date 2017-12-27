/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 12:53:05 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/27 14:17:34 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	put_pixel(t_env *env, t_pos *pos, int color)
{
	int	pts;

	pts = ((int)pos->x * 4) + ((int)pos->y * env->sline);
	env->data[pts] = color;
	env->data[++pts] = color >> 8;
	env->data[++pts] = color >> 16;
}

static void	draw_fractal(t_env *env, t_fractal *fractal, int (*f)(t_env*, t_fractal, t_pos*))
{
	t_pos	pos;
	int		pxl_color;

	pos.y = 0;
	while (pos.y < env->win_h)
	{
		pos.x = 0;
		while (pos.x < env->win_w)
		{
			pxl_color = (*f)(env, *fractal, &pos);
			put_pixel(env, &pos, pxl_color);
			pos.x++;
		}
		pos.y++;
	}
}

void	mlx_fractal(t_env *env)
{
	env->img = mlx_new_image(env->mlx, env->win_w, env->win_h);
	env->data = mlx_get_data_addr(env->img, &env->bpp, &env->sline, &env->endian);
	draw_fractal(env, env->cur_f, env->cur_f->ft);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
}
