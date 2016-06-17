/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 09:02:40 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/17 15:11:50 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	free_level(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->map.y)
	{
		free(env->map.map[i]);
		i++;
	}
}

void	load_next_level(t_env *env)
{
	env->level++;
	if (env->level < env->num_levels)
	{
		free_level(env);
		ft_printf("level freed");
		init_info(env);
	}
	else
	{
		ft_printf("You win!\n");
		exit(0);
	}
}
