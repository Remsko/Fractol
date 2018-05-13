/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 12:53:05 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/13 16:36:22 by rpinoit          ###   ########.fr       */
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

static int	color_median(int c[4])
{
	int		new_color[3];
	int		ret;
	int		mask;

	mask = 0x000000FF;
	new_color[0] = (((c[0] >> 4) & mask) + ((c[1] >> 4) & mask)
			+ ((c[2] >> 4) & mask) + ((c[3]) >> 4) & mask) / 4;
	new_color[1] = (((c[0] >> 8) & mask) + ((c[1] >> 8) & mask)
			+ ((c[2] >> 8) & mask) + ((c[3] >> 8) & mask)) / 4;
	new_color[2] = (((c[0] >> 16) & mask) + ((c[1] >> 16) & mask)
			+ ((c[2] >> 16) & mask) + ((c[3] >> 16) & mask)) / 4;
	ret = (int)new_color[2] << 16 | (int)new_color[1] << 8
		| (int)new_color[0] << 4;
	return (ret);
}

static int	draw_fractal_aa(t_env *env, t_fractal *fractal,
		int (*f)(t_env*, t_fractal, t_pos*), t_pos pos)
{
	t_pos	pix;
	int		color[4];

	pix.y = 0;
	while (pix.y < 2)
	{
		pix.x = 0;
		while (pix.x < 2)
		{
			pos = (t_pos){pos.x + pix.x * 0.5, pos.y + pix.y * 0.5};
			color[(int)pix.y * 2 + (int)pix.x] = (*f)(env, *fractal, &pos);
			pix.x++;
		}
		pix.y++;
	}
	return (color_median(color));
}

static void	draw_fractal(t_env *env, t_fractal *fractal,
		int (*f)(t_env*, t_fractal, t_pos*))
{
	t_pos	pos;
	int		pxl_color;

	pos.y = 0;
	while (pos.y < env->win_h)
	{
		pos.x = 0;
		while (pos.x < env->win_w)
		{
			if (env->active_aa != 'Y')
				pxl_color = (*f)(env, *fractal, &pos);
			else
				pxl_color = draw_fractal_aa(env, env->cur_f,
						env->cur_f->ft, pos);
			put_pixel(env, &pos, pxl_color);
			pos.x++;
		}
		pos.y++;
	}
}

void		mlx_fractal(t_env *env)
{
	env->img = mlx_new_image(env->mlx, env->win_w, env->win_h);
	env->data = mlx_get_data_addr(env->img, &env->bpp, &env->sline,
			&env->endian);
	draw_fractal(env, env->cur_f, env->cur_f->ft);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
}
