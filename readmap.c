/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 08:26:26 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/13 09:45:37 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	readmap(char *file, t_info *info)
{
	int		y;
	int		fd;
	char	**map;

	y = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_printerr("Error reading from file %s\n", file);
	if (!(map = (char **)malloc(sizeof(char *) * info->rows + 1)))
		ft_printerr("Error assigning memory for map\n");
	while (y < info->rows)
	{
		if (get_next_line(fd, &map[y]) == -1)
			ft_printerr("Error reading map\n");
		y++;
	}
	info->map = map;	//remember to free this later
}
