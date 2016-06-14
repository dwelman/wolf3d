/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaunder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:15:45 by bsaunder          #+#    #+#             */
/*   Updated: 2016/06/14 14:43:13 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			key_press(int keycode, t_env *e)
{
	if (keycode == 123 || keycode == 86)
		e->player.move.left = 1;
	if (keycode == 126 || keycode == 91)
		e->player.move.up = 1;
	if (keycode == 124 || keycode == 88)
		e->player.move.right = 1;
	if (keycode == 125 || keycode == 84)
		e->player.move.down = 1;
	if (keycode == 50)
		e->player.sprint = 1;
	return (0);
}

int			key_release(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123 || keycode == 86)
		e->player.move.left = 0;
	if (keycode == 126 || keycode == 91)
		e->player.move.up = 0;
	if (keycode == 124 || keycode == 88)
		e->player.move.right = 0;
	if (keycode == 125 || keycode == 84)
		e->player.move.down = 0;
	if (keycode == 50)
		e->player.sprint = 0;
	return (0);
}

static void	turn(t_env *e, char dir)
{
	double	tmpdir;
	double	tmpplane;
	int		coef;

	coef = 1;
	tmpdir = e->player.dir.x;
	tmpplane = e->r.plane.x;
	if (dir == 'R')
		coef = -1;
	e->player.dir.x = e->player.dir.x * cos(coef * e->player.rotspd)
		- e->player.dir.y * sin(coef * e->player.rotspd);
	e->player.dir.y = tmpdir * sin(coef * e->player.rotspd)
		+ e->player.dir.y * cos(coef * e->player.rotspd);
	e->r.plane.x = e->r.plane.x * cos(coef * e->player.rotspd) - e->r.plane.y * sin(coef * e->player.rotspd);
	e->r.plane.y = tmpplane * sin(coef * e->player.rotspd) + e->r.plane.y * cos(coef * e->player.rotspd);
}

void		move(t_env *e)
{
	if (e->player.move.up)
	{
		if (!(e->map.map[(int)(e->player.pos.x + e->player.dir.x
			* e->player.movespd)][(int)(e->player.pos.y)]))
			e->player.pos.x += e->player.dir.x * e->player.movespd;
		if (!(e->map.map[(int)(e->player.pos.x)][(int)(e->player.pos.y
			+ e->player.dir.y * e->player.movespd)]))
			e->player.pos.y += e->player.dir.y * e->player.movespd;
	}
	if (e->player.move.left)
		turn(e, 'L');
	if (e->player.move.right)
		turn(e, 'R');
	if (e->player.move.down)
	{
		if (!(e->map.map[(int)(e->player.pos.x - e->player.dir.x
			* e->player.movespd)][(int)(e->player.pos.y)]))
			e->player.pos.x -= e->player.dir.x * e->player.movespd;
		if (!(e->map.map[(int)(e->player.pos.x)][(int)(e->player.pos.y
			- e->player.dir.y * e->player.movespd)]))
			e->player.pos.y -= e->player.dir.y * e->player.movespd;
	}
	if (e->player.sprint)
		e->player.movespd *= 0.05;
}
