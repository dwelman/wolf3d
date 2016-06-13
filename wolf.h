/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 08:09:06 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/13 15:40:11 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# define WIN_X 512
# define WIN_Y 384
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125

typedef struct	s_info
{
	void		*mlx;
	void		*win;
	char		**map;
	int			rows;
	int			cols;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			col;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		time;
	double		old_time;
	double		camera_x;
	double		raypos_x;
	double		raypos_y;
	double		raydir_x;
	double		raydir_y;
}				t_info;

void			readmap(char *file, t_info *info);

void			init_info(t_info *info, int x, int y);

int				key_hook(int keycode, t_info *info);

void			cleanup(t_info *info);

void			raycast(t_info *info);

void			draw_vert_line(t_info *info, int x);

int				key_press(int keycode, t_info *info);

int				key_release(int keycode, int *f);

#endif
