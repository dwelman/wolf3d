/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 13:30:10 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/14 13:34:23 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	get_fps(t_env *env)
{
	struct timeval	time;

	env->o_time = env->time;
	gettimeofday(&time, 0);
	env->time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	env->f_time = env->time - env->o_time;
	env->info.m_speed = env->f_time * 0.004;
	env->info.r_speed = env->f_time * 0.004;
}
