/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:08:21 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/27 10:40:19 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	put_usage(t_env *env)
{
	int i;

	i = 0;
	ft_putendl("Usage : ./fractol <fractal's name>");
	ft_putstr("Available fractals: ");
	while (i < FRACTAL_NB)
	{
		ft_putstr(env->f[i].name);
		if (i < FRACTAL_NB - 1)
			ft_putstr(", ");
		i++;
	}
	ft_putchar('.');
	exit(EXIT_FAILURE);
}

static void	check_param(int ac, char **av, t_env *env)
{
	int i;

	i = 0;
	if (ac != 2)
		put_usage(env);
	while (i < FRACTAL_NB)
	{
		if (ft_strcmp(av[1], env->f[i].name) == 0)
			return ;
		i++;
	}
	put_usage(env);
}

static void	init_win(t_env *env, char *name)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->win_w, env->win_h, name);
}

int		main(int ac, char **av)
{
	t_env env;

	env.win_w = WIN_W;
	env.win_h = WIN_H;
	init_fractal(&env);
	init_color(&env);
	check_param(ac, av, &env);
	init_win(&env, av[1]);
	use_fractal(&env, av[1]);
	mlx_expose_hook(env.win, expose_hook, &env);
	mlx_key_hook(env.win, key_hook, &env);
//	mlx_mouse_hook(env.win, mouse_hook, &env);
//	mlx_hook(env.win, 6, 1L<<6, motion_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
