/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 09:02:40 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/17 10:22:44 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	load_next_level(t_env *env)
{
	env->level++;
	if (env->level < env->num_levels)
	{
		init_info(env);
	}
	else
	{
		ft_printf("You win!\n");
		exit(0);
	}
}
