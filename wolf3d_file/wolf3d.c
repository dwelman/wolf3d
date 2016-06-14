/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaunder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:15:30 by bsaunder          #+#    #+#             */
/*   Updated: 2016/06/14 14:54:28 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	readsize(t_env *e, int fd)
{
	int		*size;
	char	*line;

	if (get_next_line(fd, &line) < 1)
		exit(EXIT_FAILURE);
	size = ft_strsplittoint(line, ' ');
	e->map.sizex = size[0];
	e->map.sizey = size[1];
}

static void	readmap(t_env *e, int fd)
{
	char	*line;
	int		**worldmap;
	int		i;

	i = 0;
	worldmap = (int **)malloc(sizeof(int *) * e->map.sizex);
	if (worldmap == NULL)
		exit(EXIT_FAILURE);
	while (get_next_line(fd, &line) > 0)
	{
		worldmap[i] = ft_strsplittoint(line, ' ');
		i++;
	}
	e->map.map = worldmap;
}

static void	readfile(t_env *e)
{
	int		fd;
	int		i;

	i = 0;
	if ((fd = open("maze", O_RDONLY)) == -1)
		exit(EXIT_FAILURE);
	readsize(e, fd);
	readmap(e, fd);
	close(fd);
}

void		get_timeframe(t_env *e)
{
	struct timeval time;

	e->oldtime = e->time;
	gettimeofday(&time, 0);
	e->time = time.tv_sec * 1000 + time.tv_usec / 1000;
	e->frametime = e->time - e->oldtime;
	e->player.movespd = e->frametime * 0.003;
	e->player.rotspd = e->frametime * 0.003;
}

int			main(void)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, W, H, "Wolf3D");
	e.img.img = NULL;
	e.player.pos.x = 19;
	e.player.pos.y = 29;
	e.player.dir.x = -1;
	e.player.dir.y = 0;
	e.r.plane.x = 0;
	e.r.plane.y = 0.80;
	e.time = 0;
	e.oldtime = 0;
	readfile(&e);
	mlx_loop_hook(e.mlx, &loop_hook, &e);
	mlx_hook(e.win, 2, (1L << 0), &key_press, &e);
	mlx_hook(e.win, 3, (1L << 1), &key_release, &e);
	mlx_loop(e.mlx);
	return (0);
}
