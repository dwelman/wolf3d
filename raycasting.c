/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 13:19:27 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/15 14:12:34 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	create_ray(t_env *env, int x)
{
	env->info.camera_x = 2 * x / (double)WIN_X - 1;
	env->ray.pos.x = env->info.pos.x;
	env->ray.pos.y = env->info.pos.y;
	env->ray.dir.x = env->info.dir.x + env->ray.plane.x * env->info.camera_x;
	env->ray.dir.y = env->info.dir.y + env->ray.plane.y * env->info.camera_x;
	env->ray.posmap.x = (int)env->ray.pos.x;
	env->ray.posmap.y = (int)env->ray.pos.y;
	env->ray.deltadist.x = sqrt(1 + pow(env->ray.dir.y, 2) / pow(env->ray.dir.x, 2));
	env->ray.deltadist.y = sqrt(1 + pow(env->ray.dir.x, 2) / pow(env->ray.dir.y, 2));
	env->info.hit = 0;
}

static void	ray_dir(t_env *env)
{
	if (env->ray.dir.x < 0)
	{
		env->info.step.x = -1;
		env->ray.perpwall.x = (env->ray.pos.x - env->ray.posmap.x) * env->ray.deltadist.x;
	}
	else
	{
		env->info.step.x = 1;
		env->ray.perpwall.x = (env->ray.posmap.x + 1.0 - env->ray.pos.x) * env->ray.deltadist.x;
	}
	if (env->ray.dir.y < 0)
	{
		env->info.step.y = -1;
		env->ray.perpwall.y = (env->ray.pos.y - env->ray.posmap.y) * env->ray.deltadist.y;
	}
	else
	{
		env->info.step.y = 1;
		env->ray.perpwall.y = (env->ray.posmap.y + 1.0 - env->ray.pos.y) * env->ray.deltadist.y;
	}
}

static void	dda_alg(t_env *env)
{
	while (env->info.hit == 0)
	{
		if (env->ray.perpwall.x < env->ray.perpwall.y)
		{
			env->ray.perpwall.x += env->ray.deltadist.x;
			env->ray.posmap.x += env->info.step.x;
			env->info.wallside = 0;
		}
		else
		{
			env->ray.perpwall.y += env->ray.deltadist.y;
			env->ray.posmap.y += env->info.step.y;
			env->info.wallside = 1;
		}
		if (env->map.map[env->ray.posmap.x][env->ray.posmap.y] == '*')
			env->info.hit = 1;
	}
}

static void	calculate(t_env *env)
{
	double	wall_dist;

	if (env->info.wallside == 0)
		wall_dist = fabs((env->ray.posmap.x - env->ray.pos.x + (1 - env->info.step.x) / 2) / env->ray.dir.x);
	else
		wall_dist = fabs((env->ray.posmap.y - env->ray.pos.y + (1 - env->info.step.y) / 2) / env->ray.dir.y);
	env->ray.line_h = abs((int)(WIN_Y / wall_dist));
	env->ray.draw_s = (-1 * (env->ray.line_h)) / 2 + WIN_Y / 2;
	if (env->ray.draw_s < 0)
		env->ray.draw_s = 0;
	env->ray.draw_e = env->ray.line_h / 2 + WIN_Y / 2;
	if (env->ray.draw_e >= WIN_Y)
		env->ray.draw_e = WIN_Y - 1;
}

int			loop_hook(t_env *env)
{
	int		x;
	t_col	col;

	x = 0;
	if (env->img.img != NULL)
	{
		mlx_destroy_image(env->mlx, env->img.img);
		env->img.img = NULL;
	}
	env->img.img = mlx_new_image(env->mlx, WIN_X, WIN_Y);
	while (x < WIN_X)
	{
		create_ray(env, x);
		ray_dir(env);
		dda_alg(env);
		calculate(env);
		get_col(env, &col);
		draw_line(env, x, &col);
		x++;
	}
	get_fps(env);
	move_player(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	return (0);
}
