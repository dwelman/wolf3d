/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 09:30:46 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/23 07:13:42 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	turn(t_env *env, char dir)
{
	double	temp_dir;
	double	temp_plane;
	int		sign;

	sign = 1;
	if (dir == 'r')
		sign = -1;
	temp_dir = env->info.dir.x;
	temp_plane = env->ray.plane.x;
	env->info.dir.x = env->info.dir.x * cos(sign * env->info.r_speed)
		- env->info.dir.y * sin(sign * env->info.r_speed);
	env->info.dir.y = temp_dir * sin(sign * env->info.r_speed)
		+ env->info.dir.y * cos(sign * env->info.r_speed);
	env->ray.plane.x = env->ray.plane.x * cos(sign * env->info.r_speed)
		- env->ray.plane.y * sin(sign * env->info.r_speed);
	env->ray.plane.y = temp_plane * sin(sign * env->info.r_speed)
		+ env->ray.plane.y * cos(sign * env->info.r_speed);
}

int		key_press(int keycode, t_env *env)
{
	if (keycode == LEFT)
		env->info.move.left = 1;
	if (keycode == UP)
		env->info.move.up = 1;
	if (keycode == RIGHT)
		env->info.move.right = 1;
	if (keycode == DOWN)
		env->info.move.down = 1;
	if (keycode == SHIFT)
		env->info.sprint = 1;
	return (0);
}

int		close_window(t_env *env)
{
	ft_printf("Thanks for playing!\n");
	exit(0);
	env->level = 0;
}

int		key_release(int keycode, t_env *env)
{
	if (keycode == ESC)
	{
		ft_printf("Thanks for playing!\n");
		exit(0);
	}
	if (keycode == LEFT)
		env->info.move.left = 0;
	if (keycode == UP)
		env->info.move.up = 0;
	if (keycode == RIGHT)
		env->info.move.right = 0;
	if (keycode == DOWN)
		env->info.move.down = 0;
	if (keycode == SHIFT)
		env->info.sprint = 0;
	return (0);
}
