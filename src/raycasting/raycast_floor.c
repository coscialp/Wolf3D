/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycast_floor.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 19:28:06 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 19:58:52 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

static void		draw_floor_tex(t_cub3d *c, int y)
{
	int		x;
	int		color;
	int		tx;
	int		ty;

	x = 0;
	while (++x < c->data.res_x)
	{
		c->floor.cell.x = (int)c->floor.floor.x;
		c->floor.cell.y = (int)c->floor.floor.y;
		tx = (int)(c->tex[0].width * (c->floor.floor.x - c->floor.cell.x)) & (c->tex[0].width - 1);
		ty = (int)(c->tex[0].height * (c->floor.floor.y - c->floor.cell.y)) & (c->tex[0].height - 1);
		c->floor.floor.x += c->floor.step.x;
		c->floor.floor.y += c->floor.step.y;
		color = c->tex[0].ptr[ty * c->tex[0].width + tx];
		c->img.ptr[y * c->data.res_x + x] = color;
	}
}

void		raycast_floor(t_cub3d *c)
{
	int		y;

	y = 0;
	while (y < c->data.res_y)
	{
		c->floor.ray0.x = c->player.dir.x - c->data.plane.x;
		c->floor.ray0.y = c->player.dir.y - c->data.plane.y;
		c->floor.ray1.x = c->player.dir.x + c->data.plane.x;
		c->floor.ray1.y = c->player.dir.y + c->data.plane.y;
		c->floor.curr_pos_y = y - c->data.res_y / 2;
		c->floor.pos_z = 0.5 * c->data.res_y;
		c->floor.row = c->floor.pos_z / c->floor.curr_pos_y;
		c->floor.step.x = c->floor.row * (c->floor.ray1.x - c->floor.ray0.x) / c->data.res_x;
		c->floor.step.y = c->floor.row * (c->floor.ray1.y - c->floor.ray0.y) / c->data.res_x;
		c->floor.floor.x = c->player.pos_x + c->floor.row * c->floor.ray0.x;
		c->floor.floor.x = c->player.pos_y + c->floor.row * c->floor.ray0.y;
		draw_floor_tex(c, y);
		y++;
	}
}