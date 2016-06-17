/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 13:37:40 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/17 08:12:30 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	set_col(t_col *col, int r, int g, int b)
{
	col->r = r;
	col->g = g;
	col->b = b;
}

void	get_col(t_env *env, t_col *col)
{
	if (env->info.wallside == 0)
	{
		if (env->wall_type == 0)
			if (env->info.step.x < 0)
				set_col(col, 0, 0, 255);
			else
				set_col(col, 0, 102, 0);
		else
			set_col(col, 255, 215, 0);
	}
	else if (env->info.wallside == 1)
	{
		if (env->wall_type == 0)
			if (env->info.step.y < 0)
				set_col(col, 0, 0, 128);
			else
				set_col(col, 0, 204, 0);
		else
			set_col(col, 255, 215, 0);
	}
}
