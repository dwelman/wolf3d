/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:22:07 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/14 09:29:18 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int     rerender(t_info *info)
{
	if (info->mlx)
		mlx_clear_window(0, info->win);
	if (info->img)
		mlx_destroy_image(info->mlx, info->img);
	info->img = mlx_new_image(info->mlx, WIN_X, WIN_Y);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0 ,0);
	raycast(info);
}

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
