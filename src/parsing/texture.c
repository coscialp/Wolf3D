/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   texture.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 18:11:03 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/03/18 17:41:33 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
	load_texture(c, "./Texture_Wolf/textureXPM/oppenant_wait.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/gun_fps.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/gun_fps_shoot.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/gun_fps_aftershoot.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/oppenant_blessed.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/oppenant_blessed2.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/oppenant_blessed3.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/oppenant_dead.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/empty.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/oppenant_run.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/oppenant_run2.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/oppenant_run3.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/oppenant_run4.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/oppenant_start_shoot.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/oppenant_shoot.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/door_blue.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/knife_fps.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/knife_fps_attack.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/knife_fps_attack2.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/knife_fps_attack3.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/door_open.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/door_open2.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/door_open3.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/door_open4.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/door_open5.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/door_open6.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/door_open7.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/door_open8.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/door_open9.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/little_bullet.xpm");
	load_texture(c, "./Texture_Wolf/textureXPM/wall_stone_nazis.xpm");
}
