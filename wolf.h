/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 14:49:48 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/23 07:17:39 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <sys/time.h>
# define WIN_X 800
# define WIN_Y 600
# define TEX_X 64
# define TEX_Y 64
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define SHIFT 257
# define ENVT env->textures

typedef struct	s_col
{
	int			r;
	int			g;
	int			b;
}				t_col;

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
	int			down;
	int			left;
	int			right;
}				t_move;

typedef struct	s_ray
{
	t_coord		pos;
	t_coord		dir;
	t_coord		plane;
	t_coord		perpwall;
	t_coord		deltadist;
	t_coordint	posmap;
	int			line_h;
	int			draw_s;
	int			draw_e;
}				t_ray;

typedef struct	s_info
{
	t_coord		pos;
	t_coord		dir;
	t_coordint	step;
	t_move		move;
	double		r_speed;
	double		m_speed;
	double		camera_x;
	int			hit;
	int			wallside;
	int			sprint;
}				t_info;

typedef struct	s_map
{
	char		**map;
	int			display;
	int			x;
	int			y;
}				t_map;

typedef struct	s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				s;
	int				e;
	char			id;
	int				x;
	int				y;
}				t_img;

typedef	struct	s_env
{
	void		*win;
	void		*mlx;
	t_img		img;
	t_info		info;
	t_ray		ray;
	t_map		map;
	double		time;
	double		o_time;
	double		f_time;
	int			wall_type;
	char		**levels;
	int			level;
	int			num_levels;
}				t_env;

void			read_levels(t_env *env, char *str);

void			init_info(t_env *env);

int				loop_hook(t_env *env);

void			get_fps(t_env *env);

void			get_col(t_env *env, t_col *col);

void			set_col(t_col *col, int r, int g, int b);

int				key_press(int keycode, t_env *env);

int				key_release(int keycode, t_env *env);

void			turn(t_env *env, char dir);

void			mlx_image_put_pixel(void *mlx, t_img *i,
		t_coordint p, t_col *c);

void			move_player(t_env *env);

void			draw_line(t_env *env, int x, t_col *col);

void			free_map(t_env *env);

t_img			*get_img(char id, t_env *env);

t_col			get_texel(int x, int y, t_env *env, char id);

void			init_textures(t_env *env);

int				count_lines(char *file);

void			load_next_level(t_env *env);

int				close_window(t_env *env);

#endif
