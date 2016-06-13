/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 08:28:34 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/13 16:20:41 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_info(t_info *info, int x, int y)
{
	info->mlx = NULL;
	info->win = NULL;
	info->map = NULL;
	info->rows = x;
	info->cols = y;
	info->pos_x = 15;
	info->pos_y = 15;
	info->dir_x = -1;
	info->dir_y = -1;
	info->plane_x = 0;
	info->plane_y = 0.66;
	info->time = 0;
	info->old_time = 0;
}
