/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:22:07 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/14 08:09:27 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_vert_line(t_info *info, int x)
{
	int	y;

	y = info->draw_start;
	while (y < info->draw_end)
	{
		mlx_pixel_put(info->mlx, info->win, x, y, info->col);
		y++;
	}	
}
