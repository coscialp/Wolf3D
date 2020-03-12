/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 18:11:03 by coscialp          #+#    #+#             */
/*   Updated: 2020/03/12 19:41:14 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	load_texture(t_cub3d *c, char *path)
{
	static int i = 0;

	if ((c->tex[i].img = mlx_xpm_file_to_image(data()->ptrwin, path,
		&c->tex[i].width, &c->tex[i].height)))
		c->tex[i].ptr = (int *)mlx_get_data_addr(c->tex[i].img,
		&c->tex[i].bpp, &c->tex[i].size_line, &c->tex[i].endian);
	else
	{
		msg_error("texture");
		ft_exit(c);
	}
	i++;
}

void	loading_all_tex(t_cub3d *c)
{
	load_texture(c, data()->north_texture);
	load_texture(c, data()->south_texture);
	load_texture(c, data()->east_texture);
	load_texture(c, data()->west_texture);
	load_texture(c, data()->sprite_texture);
	load_texture(c, "./textures/sprite_1.xpm");
	load_texture(c, "./textures/sprite_1.xpm");
}
