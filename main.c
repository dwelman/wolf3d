/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 08:05:00 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/14 15:16:56 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc != 4 || ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0)
		ft_printerr("Error. Usage: [map file] [column count] [row count]\n");
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_X, WIN_Y, "Wolf3d");
	env.img.img = NULL;
	init_info(&env, argv[1], ft_atoi(argv[2]), ft_atoi(argv[2]));
	mlx_loop_hook(env.mlx, &loop_hook, &env);
	mlx_hook(env.win, 2, (1L<<0), &key_press, &env);
	mlx_hook(env.win, 3, (1L<<1), &key_release, &env);
	mlx_loop(env.mlx);
	return (0);
}
