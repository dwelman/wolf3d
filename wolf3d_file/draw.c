/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaunder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:16:54 by bsaunder          #+#    #+#             */
/*   Updated: 2016/06/14 14:02:19 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	set_colors(t_rgb *colour, int r, int g, int b)
{
	colour->r = r;
	colour->g = g;
	colour->b = b;
}

static void	mlx_image_put_pixel(void *mlx, t_img *i, t_coordint p, t_rgb *c)
{
	if (i->e)
	{
		i->d[p.y * i->s + p.x * i->bpp / 8] = mlx_get_color_value(mlx, c->r);
		i->d[p.y * i->s + p.x * i->bpp / 8 + 1] =
			mlx_get_color_value(mlx, c->g);
		i->d[p.y * i->s + p.x * i->bpp / 8 + 2] =
			mlx_get_color_value(mlx, c->b);
	}
	else
	{
		i->d[p.y * i->s + i->bpp / 8 * p.x] = mlx_get_color_value(mlx, c->b);
		i->d[p.y * i->s + i->bpp / 8 * p.x + 1] =
			mlx_get_color_value(mlx, c->g);
		i->d[p.y * i->s + i->bpp / 8 * p.x + 2] =
			mlx_get_color_value(mlx, c->r);
	}
}

void		drawline(int x, t_env *e, t_rgb *colour)
{
	t_coordint	p;
	t_rgb		skyfloor;

	p.x = x;
	e->img.d = mlx_get_data_addr(e->img.img, &e->img.bpp, &e->img.s, &e->img.e);
	set_colors(&skyfloor, 102, 178, 255);
	p.y = 0;
	while (p.y < e->r.drawstart)
	{
		mlx_image_put_pixel(e, &(e->img), p, &skyfloor);
		p.y++;
	}
	p.y = e->r.drawstart;
	while (p.y < e->r.drawend)
	{
		mlx_image_put_pixel(e, &(e->img), p, colour);
		p.y++;
	}
	set_colors(&skyfloor, 64, 64, 64);
	p.y = e->r.drawend;
	while (p.y < H)
	{
		mlx_image_put_pixel(e, &(e->img), p, &skyfloor);
		p.y++;
	}
}

void		colors(t_env *e, t_rgb *colour)
{
	if (e->player.wallside == 0)
		if (e->player.step.x < 0)
			set_colors(colour, 0, 0, 255);
		else
			set_colors(colour, 0, 102, 0);
	else if (e->player.step.y < 0)
		set_colors(colour, 0, 0, 128);
	else
		set_colors(colour, 0, 204, 0);
}
