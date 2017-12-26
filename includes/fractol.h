/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:48:21 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/26 13:16:52 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

# define FRACTAL_NB 1
# define COLOR_NB 4
# define WIN_W 1366
# define WIN_H 768
# define ESC 53

typedef struct		s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef struct		s_complex
{
	double 			r;
	double 			i;
}					t_complex;

typedef struct		s_fractal
{
	t_complex		c;
	t_complex		z;
	t_pos			pos1;
	t_pos			pos2;
	t_pos			zoom;
	double			zoom_r;
	double			tmp;
	int				i;
	int				i_max;
	void			*ft;
	char			*name;
}					t_fractal;

typedef struct		s_color
{
	int				c;
	int				c_0;
	int				c_1;
	int				c_2;
	int				c_3;
	int				c_4;
	int				c_5;
	int				c_6;
	int				c_7;
	int				c_8;
	int				c_9;
	int				c_10;
}					t_color;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				sline;
	int				endian;
	t_fractal		*f;
	t_fractal		*cur_f;
	t_color			*color;
	t_color			*cur_color;
	int				i_color;
}					t_env;

int		fractal_mandelbrot(t_env *env, t_fractal *f, t_pos *pos);
void	init_fractal(t_env *env);
void	use_fractal(t_env *env, char *name);
void	init_color(t_env *env);
int		get_color(int z, t_color color);
void	change_color(t_env *env);
void	mlx_fractal(t_env *env);
int		expose_hook(t_env *env);
int		key_hook(int key, t_env *env);

#endif
