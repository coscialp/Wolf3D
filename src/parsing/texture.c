/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   texture.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 18:11:03 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 13:05:53 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	load_texture(t_cub3d *c, char *path)
{
	static int i = 0;

	if ((c->tex[i].img = mlx_xpm_file_to_image(c->data.ptrwin, path,
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
	load_texture(c, c->data.north_texture);
	load_texture(c, c->data.south_texture);
	load_texture(c, c->data.east_texture);
	load_texture(c, c->data.west_texture);
}

void	load_tex_sprite(t_cub3d *c)
{
	static int i = 0;

	while (i < c->data.num_sprite)
	{
		if ((c->sprite[i].tex.img = mlx_xpm_file_to_image(c->data.ptrwin,
		c->data.sprite_texture, &c->sprite[i].tex.width,
		&c->sprite[i].tex.height)))
			c->sprite[i].tex.ptr =
			(int *)mlx_get_data_addr(c->sprite[i].tex.img,
			&c->sprite[i].tex.bpp, &c->sprite[i].tex.size_line,
			&c->sprite[i].tex.endian);
		else
		{
			msg_error("texture");
			ft_exit(c);
		}
		i++;
	}
}
