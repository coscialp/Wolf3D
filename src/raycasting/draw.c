/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 11:48:31 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 17:34:36 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_cub3d *c, int x)
{
	int		y;
	double	coef;
	t_color	color;

	y = c->draw_start;
	while (y < c->draw_end)
	{
		c->tex_y = (int)c->tex_pos & (c->tex[c->direction].height - 1);
		c->tex_pos += c->step;
		color.color = c->tex[c->direction].ptr[c->tex_y *
		c->tex[c->direction].width + c->tex_x];
		coef = c->zbuffer[x] < 25 ? 1 - c->zbuffer[x] / 25 : 0;
		if (c->side == 0)
		{
			color.rgba.r *= 0.7;
			color.rgba.g *= 0.7;
			color.rgba.b *= 0.7;
		}
		color.rgba.r *= coef;
		color.rgba.g *= coef;
		color.rgba.b *= coef;
		c->img.ptr[y * c->data.res_x + x] = color.color;
		y++;
	}
}

void	draw_floor(t_cub3d *c, int x)
{
	int		y;
	double	coef;
	t_color	color;

	y = c->data.res_y - 1;
	while (y >= c->draw_end)
	{
		coef = y - (c->data.res_y / 2) > ((c->data.res_y / 2) / 2) ? (1 - (y - (c->data.res_y / 2)) / ((c->data.res_y / 2) / 2)) : 0;
		color.color = c->data.col_floor;
		color.rgba.r *= coef;
		color.rgba.g *= coef;
		color.rgba.b *= coef;
		c->img.ptr[y * c->data.res_x + x] = color.color;
		y--;
	}
}

void	draw_ceilling(t_cub3d *c, int x)
{
	int		y;
	double	coef;
	t_color	color;

	y = 0;
	while (y < c->draw_start)
	{
		coef = ((c->data.res_y / 2) + c->move_cam - y) < (c->data.res_y / 2) ? (1 - ((c->data.res_y / 2) + c->move_cam - y) / 11) : 1;
		color.color = c->data.col_ceil;
		color.rgba.r *= coef;
		color.rgba.g *= coef;
		color.rgba.b *= coef;
		c->img.ptr[y * c->data.res_x + x] = color.color;
		y++;
	}
}

void	draw(t_cub3d *c, int x)
{
	draw_wall(c, x);
	draw_floor(c, x);
	draw_ceilling(c, x);
}
