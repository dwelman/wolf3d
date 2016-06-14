/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 09:30:46 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/14 08:35:42 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	key_press(int keycode, t_info *info)
{
	if (keycode == ESC)
	{
		ft_printf("Thanks for playing!\n");
		cleanup(info);
	}
	if (keycode == UP)
	{
		if (info->map[(int)(info->pos_x + info->dir_x * info->move_speed)][(int)info->pos_y] == '0')
			info->pos_x += info->dir_x * info->move_speed;
		if (info->map[(int)info->pos_x][(int)(info->pos_y + info->pos_y * info->move_speed)] == '0')
			info->pos_y += info->dir_y * info->move_speed;
	}
	if (keycode == DOWN)
	{
		if (info->map[(int)(info->pos_x - info->dir_x * info->move_speed)][(int)info->pos_y] == '0')
			info->pos_x -= info->dir_x * info->move_speed;
		if (info->map[(int)info->pos_x][(int)(info->pos_y - info->pos_y * info->move_speed)] == '0')
			info->pos_y -= info->dir_y * info->move_speed;
	}
	if (keycode == RIGHT)
	{
		info->old_dir_x = info->dir_x;
		info->dir_x = info->dir_x * cos(-info->rot_speed) - info->dir_y * sin(-info->rot_speed);
		info->dir_y = info->old_dir_x * sin(-info->rot_speed) + info->dir_y * cos(-info->rot_speed);
		info->old_plane_x = info->plane_x;
		info->plane_x = info->plane_x * cos(-info->rot_speed) - info->plane_y * sin(-info->rot_speed);
		info->plane_y = info->old_plane_x * sin(-info->rot_speed) + info->plane_y * cos(-info->rot_speed);
	}
	if (keycode == LEFT)
	{
		info->old_dir_x = info->dir_x;
		info->dir_x = info->dir_x * cos(info->rot_speed) - info->dir_y * sin(info->rot_speed);
		info->dir_y = info->old_dir_x * sin(info->rot_speed) + info->dir_y * cos(info->rot_speed);
		info->old_plane_x = info->plane_x;
		info->plane_x = info->plane_x * cos(info->rot_speed) - info->plane_y * sin(info->rot_speed);
		info->plane_y = info->old_plane_x * sin(info->rot_speed) + info->plane_y * cos(info->rot_speed);
	}
	rerender(info);
	return (0);
}

int	key_release(int keycode, t_info *info)
{
	return (0);
}

int	key_hook(int keycode, t_info *info)
{
	if (keycode != 256)
		ft_printf("%d\n", keycode);
	return (0);
}
