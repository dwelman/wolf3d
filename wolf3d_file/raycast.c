/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaunder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:16:13 by bsaunder          #+#    #+#             */
/*   Updated: 2016/06/13 15:16:37 by bsaunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		initray(t_env *e, int x)
{
	e->player.camerax = 2 * x / (double)(W) - 1;
	e->r.pos.x = e->player.pos.x;
	e->r.pos.y = e->player.pos.y;
	e->r.dir.x = e->player.dir.x + e->r.plane.x * e->player.camerax;
	e->r.dir.y = e->player.dir.y + e->r.plane.y * e->player.camerax;
	e->r.posmap.x = (int)e->r.pos.x;
	e->r.posmap.y = (int)e->r.pos.y;
	e->r.deltadist.x = sqrt(1 + (e->r.dir.y * e->r.dir.y)
			/ (e->r.dir.x * e->r.dir.x));
	e->r.deltadist.y = sqrt(1 + (e->r.dir.x * e->r.dir.x)
			/ (e->r.dir.y * e->r.dir.y));
	e->player.hit = 0;
}

static void		raydir(t_env *e)
{
	if (e->r.dir.x < 0)
	{
		e->player.step.x = -1;
		e->r.perpwall.x = (e->r.pos.x - e->r.posmap.x) * e->r.deltadist.x;
	}
	else
	{
		e->player.step.x = 1;
		e->r.perpwall.x = (e->r.posmap.x + 1.0 - e->r.pos.x) * e->r.deltadist.x;
	}
	if (e->r.dir.y < 0)
	{
		e->player.step.y = -1;
		e->r.perpwall.y = (e->r.pos.y - e->r.posmap.y) * e->r.deltadist.y;
	}
	else
	{
		e->player.step.y = 1;
		e->r.perpwall.y = (e->r.posmap.y + 1.0 - e->r.pos.y) * e->r.deltadist.y;
	}
}

static void		dda(t_env *e)
{
	while (e->player.hit == 0)
	{
		if (e->r.perpwall.x < e->r.perpwall.y)
		{
			e->r.perpwall.x += e->r.deltadist.x;
			e->r.posmap.x += e->player.step.x;
			e->player.wallside = 0;
		}
		else
		{
			e->r.perpwall.y += e->r.deltadist.y;
			e->r.posmap.y += e->player.step.y;
			e->player.wallside = 1;
		}
		if (e->map.map[e->r.posmap.x][e->r.posmap.y] > 0)
			e->player.hit = 1;
	}
}

static void		compute(t_env *e)
{
	double distwall;

	if (e->player.wallside == 0)
		distwall = fabs((e->r.posmap.x - e->r.pos.x
					+ (1 - e->player.step.x) / 2) / e->r.dir.x);
	else
		distwall = fabs((e->r.posmap.y - e->r.pos.y
					+ (1 - e->player.step.y) / 2) / e->r.dir.y);
	e->r.lineheight = abs((int)(H / distwall));
	e->r.drawstart = (-1 * (e->r.lineheight)) / 2 + H / 2;
	if (e->r.drawstart < 0)
		e->r.drawstart = 0;
	e->r.drawend = e->r.lineheight / 2 + H / 2;
	if (e->r.drawend >= H)
		e->r.drawend = H - 1;
}

int				loop_hook(t_env *e)
{
	t_rgb	c;
	int		x;

	if (e->img.img != NULL)
	{
		mlx_destroy_image(e->mlx, e->img.img);
		e->img.img = NULL;
	}
	e->img.img = mlx_new_image(e->mlx, W, H);
	x = 0;
	while (x < W)
	{
		initray(e, x);
		raydir(e);
		dda(e);
		compute(e);
		colors(e, &c);
		drawline(x, e, &c);
		x++;
	}
	get_timeframe(e);
	move(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	return (0);
}
