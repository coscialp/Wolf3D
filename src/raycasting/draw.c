/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 11:48:31 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/05 15:31:52 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_cub3d *c, int x)
{
	int		y;

	y = c->draw_start - c->sneak;
	while (y < c->draw_end)
	{
		c->tex_y = (int)c->tex_pos & (c->tex[c->direction].height - 1);
		c->tex_pos += c->step;
		c->img.ptr[y * c->data.res_x + x] = c->tex[c->direction].ptr[c->tex_y *
		c->tex[c->direction].width + c->tex_x];
		// c->img.ptr[y * c->data.res_x + x] = 0x00ff00;
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
	while (y < c->draw_start - c->sneak)
	{
		c->img.ptr[y * c->data.res_x + x] = c->data.col_ceil;
		y++;
	}
}

void	draw(t_cub3d *c, int x)
{
	draw_wall(c, x);
	draw_floor(c, x);
	draw_ceilling(c, x);
}
