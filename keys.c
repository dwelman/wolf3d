/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 09:30:46 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/13 15:43:46 by ddu-toit         ###   ########.fr       */
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
		ft_printf("Going Forward! (eventually)\n");
	}
	if (keycode == DOWN)
	{
		ft_printf("Going Backwards! (eventually)\n");
	}
	if (keycode == LEFT)
	{
		ft_printf("Going LEFT! (eventually)\n");
	}
	if (keycode == RIGHT)
	{
		ft_printf("Going RIGHT! (eventually)\n");
	}
	return (0);
}

int	key_release(int keycode, int *f)
{
	return (0);
}

int	key_hook(int keycode, t_info *info)
{
	if (keycode != 256)
		ft_printf("%d\n", keycode);
	return (0);
}
