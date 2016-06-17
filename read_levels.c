/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_levels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 08:14:24 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/17 09:39:38 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	read_levels(t_env *env, char *str)
{
	int		i;
	int		fd;
	char	**lines;

	i = 0;
	env->num_levels = count_lines(str);
	if ((fd = open(str, O_RDONLY)) == -1)
		ft_printerr("Error reading from file %s\n", str);
	lines = (char **)malloc(sizeof(char *) * env->num_levels + 1);
	while (i < env->num_levels)
	{
		if (get_next_line(fd, &lines[i]) == -1)
			ft_printerr("Error reading file\n");
		i++;
	}
	close(fd);
	env->levels = lines;
	env->level = 0;
}
