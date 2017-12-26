/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:48:21 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/26 17:43:47 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

# define FRACTAL_NB 3
# define COLOR_NB 4
# define WIN_W 1200
# define WIN_H 1200
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
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			zoom_x;
	double			zoom_y;
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
	double			win_w;
	double			win_h;
}					t_env;

int		fractal_mandelbrot(t_env *env, t_fractal f, t_pos *pos);
int		fractal_julia(t_env *env, t_fractal f, t_pos *pos);
int		fractal_mandelbar(t_env *env, t_fractal f, t_pos *pos);
void	init_fractal(t_env *env);
void	use_fractal(t_env *env, char *name);
void	init_color(t_env *env);
int		get_color(int z, t_color color);
void	change_color(t_env *env);
void	mlx_fractal(t_env *env);
int		expose_hook(t_env *env);
int		key_hook(int key, t_env *env);

#endif
