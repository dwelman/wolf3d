/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 08:09:06 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/13 11:53:52 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft/libft.h"
# include <mlx.h>
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

#endif
