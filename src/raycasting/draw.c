/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 11:48:31 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 19:48:28 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_cub3d *c, int x)
{
	int		y;
	int		color;

	y = c->draw_start;
	while (y < c->draw_end)
	{
		c->tex_y = (int)c->tex_pos & (c->tex[c->direction].height - 1);
		c->tex_pos += c->step;
		color = c->tex[c->direction].ptr[c->tex_y *
		c->tex[c->direction].width + c->tex_x];
		c->img.ptr[y * c->data.res_x + x] = color;
		y++;
	}
}

void	draw_floor(t_cub3d *c, int x)
{
	int		y;
	y = c->draw_end;
	while (y < c->data.res_y)
	{
		c->img.ptr[y * c->data.res_x + x] = c->data.col_floor;
		y++;
	}
}

void	draw_ceilling(t_cub3d *c, int x)
{
	int		y;

	y = 0;
	while (y < c->draw_start)
	{
		c->img.ptr[y * c->data.res_x + x] = c->data.col_ceil;
		y++;
	}
}

void	draw_pixel_sprite(t_cub3d *c, int stripe, t_pos tex, int y)
{
	int color;
	int d;

	d = (y - c->move_cam) * 256 - c->data.res_y *
	128 + c->sprite_height * 128;
	tex.y = ((d * c->sprite[0].tex.height) / c->sprite_height) / 256;
	color = c->sprite[0].tex.ptr[tex.y * c->sprite[0].tex.width + tex.x];
	if ((color & 0xffffff) != 0)
		c->img.ptr[y * c->data.res_x + stripe] = color;
}

void	draw_sprite(t_cub3d *c)
{
	int			stripe;
	int			y;
	t_pos		tex;

	stripe = c->sprite_start.x;
	while (stripe < c->sprite_end.x)
	{
		tex.x = (int)((256 * (stripe -
		(-c->sprite_width / 2 + c->sprite_screen)) *
		c->sprite[0].tex.width / c->sprite_width) / 256);
		if (c->transform.y > 0 && stripe > 0 && stripe < c->data.res_x
		&& c->transform.y < c->zbuffer[stripe])
		{
			y = c->sprite_start.y - 1;
			while (++y < c->sprite_end.y)
				draw_pixel_sprite(c, stripe, tex, y);
		}
		stripe++;
	}
}

void	draw(t_cub3d *c, int x)
{
	draw_wall(c, x);
	// draw_floor(c, x);
	draw_ceilling(c, x);
}
