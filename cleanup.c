/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 10:12:16 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/13 10:50:23 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	cleanup(t_info *info)
{
	int	y;

	y = 0;
	if (info->map != NULL)
	{
		while (y < info->rows)
		{
			free(info->map[y]);
			y++;
		}
		free(info->map);
	}
	exit(0);
}
