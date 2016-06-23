/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 08:05:00 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/23 07:18:17 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	main(void)
{
	t_env	env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_X, WIN_Y, "Wolf3d");
	env.img.img = NULL;
	read_levels(&env, "levels");
	env.info.pos.x = 0;
	env.info.pos.y = 0;
	init_info(&env);
	mlx_loop_hook(env.mlx, &loop_hook, &env);
	if (env.mlx == NULL || env.win == NULL)
		exit(0);
	mlx_hook(env.win, 2, (1L << 0), &key_press, &env);
	mlx_hook(env.win, 3, (1L << 1), &key_release, &env);
	mlx_hook(env.win, 17, 0L, &close_window, &env);
	mlx_loop(env.mlx);
	return (0);
}
