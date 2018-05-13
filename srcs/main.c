/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:08:21 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/28 14:19:49 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	put_usage(t_env *env)
{
	int i;

	i = 0;
	ft_putendl("~");
	ft_putendl("Usage : ./fractol <fractal's name>");
	ft_putstr("Available fractals: ");
	while (i < 4)
	{
		ft_putstr(env->f[i].name);
		if (i < 3)
			ft_putstr(", ");
		i++;
	}
	ft_putendl(".");
	ft_putendl("~");
	exit(EXIT_FAILURE);
}

static void	check_param(int ac, char **av, t_env *env)
{
	int i;

	i = 0;
	if (ac != 2)
		put_usage(env);
	while (i < 4)
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

int			main(int ac, char **av)
{
	t_env env;

	env.win_w = WIN_W;
	env.win_h = WIN_H;
	env.active_m = 'Y';
	env.active_aa = 'N';
	init_fractal(&env);
	init_color(&env);
	check_param(ac, av, &env);
	init_win(&env, av[1]);
	use_fractal(&env, av[1]);
	mlx_expose_hook(env.win, expose_hook, &env);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_mouse_hook(env.win, mouse_hook, &env);
	mlx_hook(env.win, 6, 1L << 6, motion_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
