/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 13:19:27 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/13 14:21:36 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	raycast(t_info *info)
{
	int	x;

	x = 0;
	while (x < WIN_X)
	{
		info->camera_x = 2 * x / (double)WIN_X - 1;
		info->raypos_x = info->pos_x;
		info->raypos_y = info->pos_y;
		info->raydir_x = info->dir_x + info->plane_x * info->camera_x;
		info->raydir_y = info->dir_y + info->plane_y * info->camera_x;
		info->map_x = (int)info->raypos_x;
		info->map_y = (int)info->raypos_y;
		info->delta_dist_x = sqrt(1 + pow(info->raydir_y, 2) / pow(info->raydir_x, 2));
		info->delta_dist_y = sqrt(1 + pow(info->raydir_x, 2) / pow(info->raydir_y, 2));
		info->hit = 0;
		if (info->raydir_x < 0)
		{
			info->step_x = -1;
			info->side_dist_x = (info->raypos_x - info->map_x) * info->delta_dist_x;
		}
		else
		{
			info->step_x = 1;
			info->side_dist_x = (info->map_x + 1.0 - info->raypos_x) * info->delta_dist_x;
		}
		if (info->raydir_y < 0)
		{
			info->step_y = -1;
			info->side_dist_y = (info->raypos_y - info->map_y) * info->delta_dist_y;
		}
		else
		{
			info->step_y = 1;
			info->side_dist_y = (info->map_y + 1.0 - info->raypos_y) * info->delta_dist_y;
		}
		while (info->hit == 0)
		{
			if (info->side_dist_x < info->side_dist_y)
			{
				info->side_dist_x += info->delta_dist_x;
				info->map_x+= info->step_x;
				info->side = 0;
			}
			else
			{
				info->side_dist_y += info->delta_dist_y;
				info->map_y+= info->step_y;
				info->side = 1;
			}
			if (info->map[info->map_x][info->map_y] != '0')
				info->hit = 1;
		}
		x++;
	}
}
