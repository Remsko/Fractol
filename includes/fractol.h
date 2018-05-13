/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:48:21 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/13 16:28:04 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

# define WIN_H 1000
# define WIN_W 1000

# define PAD_MINUS 78
# define PAD_PLUS 69
# define RIGHT_CLICK 1
# define LEFT_CLICK 2
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define KEY_ENTER 36
# define KEY_ESCAPE 53
# define KEY_MINUS 27
# define KEY_PLUS 24
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_LEFT 124
# define KEY_DOWN 126
# define KEY_RIGHT 123
# define KEY_UP 125
# define KEY_SPACE 49
# define KEY_A 0

typedef struct		s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef struct		s_complex
{
	double			r;
	double			i;
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
	char			active_m;
	char			active_aa;
}					t_env;

int					fractal_mandelbrot(t_env *env, t_fractal f, t_pos *pos);
int					fractal_julia(t_env *env, t_fractal f, t_pos *pos);
int					fractal_mandelbar(t_env *env, t_fractal f, t_pos *pos);
int					fractal_burningship(t_env *env, t_fractal f, t_pos *pos);
void				init_fractal(t_env *env);
void				use_fractal(t_env *env, char *name);
void				init_color(t_env *env);
int					get_color(int z, t_color color);
void				change_color(t_env *env);
void				mlx_fractal(t_env *env);
int					expose_hook(t_env *env);
int					key_hook(int key, t_env *env);
void				fractal_translate(t_env *env, int distance, char axis);
void				change_i(t_env *env, int i);
int					motion_hook(int x, int y, t_env *env);
int					mouse_hook(int button, int x, int y, t_env *env);

#endif
