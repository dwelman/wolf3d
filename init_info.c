/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 08:28:34 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/13 08:55:31 by daviwel          ###   ########.fr       */
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
}
