/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 08:28:34 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/15 15:03:00 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		count_lines(char *file)
{
	int	i;
	int	fd;
	char	*line;

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_printerr("Error reading from file %s\n", file);
	while (get_next_line(fd, &line))
	{
		if (line)
			free(line);
		i++;
	}
	close(fd);
	return (i);
}

void	get_player(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	while (x < env->map.x)
	{
		y = 0;
		while (y < env->map.y)
		{
			if (env->map.map[x][y] == 'X')
			{
				env->info.pos.x = x;
				env->info.pos.y = y;
			}
			y++;
		}
		x++;
	}
}

void	init_info(t_env *env, char *file)
{
	int		i;
	int		fd;
	char	**map;

	i = 0;
	env->map.y = count_lines(file);
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_printerr("Error reading from file %s\n", file);
	ft_printf("%d\n", env->map.y);
	if (!(map = (char **)malloc(sizeof(char *) * env->map.y + 1)))
		ft_printerr("Error assigning memory for map\n");
	env->map.x = 0;
	while (i < env->map.y)
	{
		if (get_next_line(fd, &map[i]) == -1)
			ft_printerr("Error reading map\n");
		if ((int)ft_strlen(map[i]) > env->map.x)
			env->map.x = ft_strlen(map[i]);
		i++;
	}
	ft_printf("%d\n", env->map.x);
	i = 0;
	while (i < env->map.y)
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	env->info.dir.x = -1;
	env->info.dir.y = 0;
	env->ray.plane.x = 0;
	env->ray.plane.y = 0.80;
	env->time = 0;
	env->o_time = 0;
	env->map.map = map;
	get_player(env);
	close(fd);
}
