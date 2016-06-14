/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 08:05:00 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/14 08:34:28 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 4 || ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0)
		ft_printerr("Error. Usage: [map file] [column count] [row count]\n");
	init_info(&info, ft_atoi(argv[2]), ft_atoi(argv[3]));
	readmap(argv[1], &info);
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, WIN_X, WIN_Y, "Wolf3d");
	raycast(&info);
	mlx_hook(info.win, 2, (1L<<0), &key_press, &info);
	mlx_hook(info.win, 3, (1L<<1), &key_release, &info);
	//mlx_key_hook(info.win, key_hook, &info);
	mlx_loop(info.mlx);
	return (0);
}
