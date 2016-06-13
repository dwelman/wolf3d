/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 13:19:27 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/13 13:48:30 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	raycast(t_info *info)
{
	int	x;

	x = 0;
	while (x < WIN_X)
	{
		camera_x = 2 * x / (double)WIN_X - 1;
		raypos_x = pos_x;
		raypos_y = pos_y;
		raydir_x = dir_x + plane_x * camera_x;
		raydir_y = dir_y + plane_y * camera_x;
		x++;
	}
}
