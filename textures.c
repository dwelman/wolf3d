/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 15:01:10 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/17 07:54:42 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_textures(t_env *env)
{
	int i;

	i = 0;
	env->tex_count = 2;
	ENVT = (t_img*)malloc(sizeof(t_img) * env->tex_count);
	ENVT[0].img = mlx_xpm_file_to_image(env->mlx, "texture/wall1v.xpm", &ENVT[0].x, &ENVT[0].y);
	if (ENVT[0].img == NULL)
		ft_printerr("ERROR : couldn't read image from file.\n");
	ENVT[0].data = (unsigned char)mlx_get_data_addr(ENVT[0].img, &ENVT[0].bpp, &ENVT[0].s, &ENVT[0].e);
	ENVT[0].id = '.';
	ENVT[1].img = mlx_xpm_file_to_image(env->mlx, "texture/wall2v.xpm", &ENVT[1].x, &ENVT[1].y);
	ENVT[1].data =  (unsigned char)mlx_get_data_addr(ENVT[1].img, &ENVT[1].bpp, &ENVT[1].s, &ENVT[1].e);
	ENVT[1].id = '*';
}

t_img	*get_img(char id, t_env *env)
{
	int	i;

	i = 0;
	while (i < env->tex_count)
	{
		if (ENVT[i].id == id)
		{
			env->tex_num = i;
			return (&ENVT[i]);
		}
		i++;
	}
	return (NULL);
}

t_col	get_texel(int x, int y, t_env *env, char id)
{
	int		pos;
	t_img	*cur;
	char	*img;
	int		num;
	t_col	ret;

	if(!(cur = get_img(id, env)))
		ft_printerr("Error finding texture %c\n", id);
	t_coordint	p;
	p.y = 0;
	mlx_put_image_to_window(env->mlx, env->win, cur->img, 64, 0);
	img = cur->img;
	while (p.y < TEX_Y)
	{
		p.x = 0;
		while (p.x < TEX_X)
		{
			pos = 0;
			pos += p.y * TEX_Y;
			pos += p.x;
			//mlx_pixel_put(env->mlx,env->win, p.x, p.y, cur->data[pos]);//+ cur->data[pos] * 256 + cur->data[pos] * 65536);
			//ft_printf("data at pos : %d \n x = %d, y = %d \nDATA : %p", pos, x, y, &cur->img[pos]);
			p.x++;
		}
		p.y++;
	}
//	write(1, &cur->data[0], cur->bpp);
//	write(1, "\n", 1);
}
