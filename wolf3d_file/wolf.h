/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaunder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:17:14 by bsaunder          #+#    #+#             */
/*   Updated: 2016/06/14 15:02:13 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <unistd.h>
# include "libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/time.h>

# define H 480
# define W 640

typedef struct	s_coord
{
	double		x;
	double		y;
}				t_coord;

typedef struct	s_coordint
{
	int			x;
	int			y;
}				t_coordint;

typedef struct	s_move
{
	int			up;
	int			left;
	int			right;
	int			down;
}				t_move;

typedef struct	s_ray
{
	t_coord		pos;
	t_coord		dir;
	t_coord		plane;
	t_coord		perpwall;
	t_coord		deltadist;
	t_coordint	posmap;
	int			lineheight;
	int			drawstart;
	int			drawend;
}				t_ray;

typedef struct	s_player
{
	t_coord		pos;
	t_coord		dir;
	t_coordint	step;
	t_move		move;
	double		rotspd;
	double		movespd;
	double		camerax;
	int			hit;
	int			wallside;
	int			sprint;
}				t_player;

typedef struct	s_map
{
	int			**map;
	int			display;
	int			sizex;
	int			sizey;
}				t_map;

typedef struct	s_img
{
	void		*img;
	char		*d;
	int			bpp;
	int			s;
	int			e;
}				t_img;

typedef struct	s_env
{
	void		*win;
	void		*mlx;
	t_img		img;
	t_player	player;
	t_map		map;
	t_ray		r;
	double		time;
	double		oldtime;
	long int	frametime;
}				t_env;

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

void			get_timeframe(t_env *e);
int				expose_hook(t_env *t);
int				loop_hook(t_env *e);
int				key_release(int keycode, t_env *e);
int				key_press(int keycode, t_env *e);
void			output(t_env *e);
void			move(t_env *e);
void			colors(t_env *e, t_rgb *c);
void			drawline(int x, t_env *e, t_rgb *c);

#endif
