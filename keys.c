/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 09:30:46 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/13 10:24:19 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	key_hook(int keycode, t_info *info)
{
	if (keycode == ESC)
	{
		ft_printf("Thanks for playing!\n");
		exit(0);
	}
	if (keycode != 256)
		ft_printf("%d\n", keycode);
	return (0);
}
