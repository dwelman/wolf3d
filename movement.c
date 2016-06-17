/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:03:26 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/17 15:04:57 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	move_up(t_env *env)
{
	if (env->info.move.up)
	{
		if (!(env->map.map[(int)(env->info.pos.x + env->info.dir.x
						* env->info.m_speed)][(int)(env->info.pos.y)] == '*'))
			env->info.pos.x += env->info.dir.x * env->info.m_speed;
		if (!(env->map.map[(int)(env->info.pos.x)][(int)(env->info.pos.y
						+ env->info.dir.y * env->info.m_speed)] == '*'))
			env->info.pos.y += env->info.dir.y * env->info.m_speed;
		if (env->map.map[(int)(env->info.pos.x)][(int)(env->info.pos.y)] == '#')
			load_next_level(env);
	}
}

void	move_player(t_env *env)
{
	move_up(env);
	if (env->info.move.left)
		turn(env, 'l');
	if (env->info.move.right)
		turn(env, 'r');
	if (env->info.move.down)
	{
		if (!(env->map.map[(int)(env->info.pos.x - env->info.dir.x
						* env->info.m_speed)]
					[(int)(env->info.pos.y)] == '*'))
			env->info.pos.x -= env->info.dir.x * env->info.m_speed;
		if (!(env->map.map[(int)(env->info.pos.x)]
					[(int)(env->info.pos.y - env->info.dir.y
						* env->info.m_speed)] == '*'))
			env->info.pos.y -= env->info.dir.y * env->info.m_speed;
		if (env->map.map[(int)(env->info.pos.x)][(int)(env->info.pos.y)] == '#')
			load_next_level(env);
	}
}
