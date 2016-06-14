/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 08:28:34 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/14 15:29:05 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_info(t_env *env, char *file, int x, int y)
{
	int		i;
	int		fd;
	char	**map;

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_printerr("Error reading from file %s\n", file);
	if (!(map = (char **)malloc(sizeof(char *) * y + 1)))
		ft_printerr("Error assigning memory for map\n");
	while (i < y)
	{
		if (get_next_line(fd, &map[i]) == -1)
			ft_printerr("Error reading map\n");
		i++;
	}
	env->info.pos.x = x / 2;
	env->info.pos.y = y / 2;
	env->info.dir.x = -1;
	env->info.dir.y = 0;
	env->ray.plane.x = 0;
	env->ray.plane.y = 0.80;
	env->time = 0;
	env->o_time = 0;
	env->map.map = map; //remember to free this later
}
