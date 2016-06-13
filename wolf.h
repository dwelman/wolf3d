/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 08:09:06 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/13 08:55:20 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft/libft.h"
# include <mlx.h>

typedef struct	s_info
{
	void		*mlx;
	void		*win;
	char		**map;
	int			rows;
	int			cols;
}				t_info;

void			readmap(char *file, t_info *info);

void			init_info(t_info *info, int x, int y);

#endif
