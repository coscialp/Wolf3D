/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_hud.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 13:09:33 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 17:07:41 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_hud_up(t_cub3d *c)
{
	int		x;
	int		y;
	int		color;
	t_pos	tex;

	x = (c->data.res_x - c->tex[4].width) / 2;
	tex.x = 0;
	while (x < c->data.res_x && tex.x < c->tex[4].width)
	{
		y = 0;
		tex.y = 0;
		while (y < (c->data.res_x / 2) && tex.y < c->tex[4].height)
		{
			color = c->tex[4].ptr[tex.y * c->tex[4].width + tex.x];
			if ((color & 0xffffff) != 0)
				c->img.ptr[y * c->data.res_x + x] = color;
			y++;
			tex.y++;
		}
		x++;
		tex.x++;
	}
}

void	draw_hud_800p(t_cub3d *c)
{
	int		x;
	int		y;
	int		color;
	t_pos	tex;

	x = (c->data.res_x - c->tex[5].width) / 2;
	tex.x = 0;
	while (x < c->data.res_x && tex.x < c->tex[5].width)
	{
		y = 0;
		tex.y = 0;
		while (y < (c->data.res_x / 2) && tex.y < c->tex[5].height)
		{
			color = c->tex[5].ptr[tex.y * c->tex[5].width + tex.x];
			if ((color & 0xffffff) != 0)
				c->img.ptr[y * c->data.res_x + x] = color;
			y++;
			tex.y++;
		}
		x++;
		tex.x++;
	}
}

void	draw_weapons(t_cub3d *c, int i)
{
	int		x;
	int		y;
	int		color;
	t_pos	tex;

	x = (c->data.res_x / 2);
	tex.x = 0;
	while (x < c->data.res_x && tex.x < c->weapons[i].width)
	{
		y = c->data.res_y;
		tex.y = c->weapons[i].height - 1;
		while (y-- && tex.y)
		{
			color = c->weapons[i].ptr[tex.y * c->weapons[i].width + tex.x];
			if ((color & 0xffffff) != 0)
				c->img.ptr[y * c->data.res_x + x] = color;
			tex.y--;
		}
		x++;
		tex.x++;
	}
}

void	draw_lifebar(t_cub3d *c)
{
	int		width_lifebar;
	int		start;
	int		x;
	int		temp_start;
	double	percentage;

	x = c->data.res_y - 60;
	start = c->data.res_x / 4;
	temp_start = start;
	width_lifebar = c->data.res_x / 2;
	percentage = (width_lifebar / 100.0) * (100.0 - c->player.life);

	while (x < c->data.res_y)
	{
		start = (c->data.res_x / 4) - 10;
		while (start < width_lifebar + temp_start + 10)
		{
			c->img.ptr[x * c->data.res_x + start] = 0;
			start++;
		}
		x++;
	}
	x = c->data.res_y - 50;
	while (x < c->data.res_y - 10)
	{
		start = c->data.res_x / 4;
		while (start < (width_lifebar + temp_start) - percentage)
		{
			c->img.ptr[x * c->data.res_x + start] = 0x00ff00;
			start++;
		}
		x++;
	}
}

void	draw_hud(t_cub3d *c)
{
	if (c->data.res_x < 1680 && c->data.res_y < 925)
		draw_hud_800p(c);
	else if (c->data.res_x >= 1680 && c->data.res_y >= 925)
		draw_hud_up(c);
	if (c->data.res_x < 1680 && c->data.res_y < 925)
		draw_weapons(c, 1);
	else if (c->data.res_x >= 1680 && c->data.res_y >= 925)
		draw_weapons(c, 0);
	draw_lifebar(c);
}
