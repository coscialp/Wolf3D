/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_sprite.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 11:45:43 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 11:46:07 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_pixel_sprite(t_cub3d *c, t_pos tex, int y, int i)
{
	int color;
	int d;

	d = (y - c->move_cam) * 256 - c->data.res_y *
	128 + c->sprite_height * 128;
	tex.y = ((d * c->tex[i].height) / c->sprite_height) / 256;
	color = c->tex[i].ptr[tex.y * c->tex[i].width + tex.x];
	if ((color & 0xffffff) != 0)
		c->img.ptr[y * c->data.res_x + c->stripe] = color;
}

void	draw_sprite(t_cub3d *c, int i)
{
	int			y;
	t_pos		tex;

	c->stripe = c->sprite_start.x;
	while (c->stripe < c->sprite_end.x)
	{
		tex.x = (int)((256 * (c->stripe -
		(-c->sprite_width / 2 + c->sprite_screen)) *
		c->tex[i].width / c->sprite_width) / 256);
		if (c->transform.y > 0 && c->stripe > 0 && c->stripe < c->data.res_x
		&& c->transform.y < c->zbuffer[c->stripe])
		{
			y = c->sprite_start.y - 1;
			while (++y < c->sprite_end.y)
				draw_pixel_sprite(c, tex, y, i);
		}
		c->stripe++;
	}
}
