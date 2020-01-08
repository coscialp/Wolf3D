/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   texture.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 18:11:03 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 18:56:05 by coscialp    ###    #+. /#+    ###.fr     */
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

void	load_weapons_tex(t_cub3d *c, char *path)
{
	static int i = 0;

	if ((c->weapons[i].img = mlx_xpm_file_to_image(c->data.ptrwin, path,
		&c->weapons[i].width, &c->weapons[i].height)))
		c->weapons[i].ptr = (int *)mlx_get_data_addr(c->weapons[i].img,
		&c->weapons[i].bpp, &c->weapons[i].size_line, &c->weapons[i].endian);
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
	load_texture(c, "./texture/hud_up.xpm");
	load_texture(c, "./texture/hud_800p.xpm");
	load_texture(c, c->data.sprite_texture);
	load_texture(c, "./textures/sprite_1.xpm");
	load_weapons_tex(c, "./texture/gun.xpm");
	load_weapons_tex(c, "./texture/gun_320p.xpm");
}
