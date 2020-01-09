/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   icanmove.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 15:29:36 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 11:40:20 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	icanmove_x(t_cub3d *c, char orientation)
{
	if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'1' && orientation == 'U')
		c->player.pos_x -= c->player.dir.x * c->movspeed;
	else if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'1' && orientation == 'D')
		c->player.pos_x += c->player.dir.x * c->movspeed;
	itsanobject_ud(c, orientation);
}

void	icanmove_y(t_cub3d *c, char orientation)
{
	if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'1' && orientation == 'U')
		c->player.pos_y -= c->player.dir.y * c->movspeed;
	else if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'1' && orientation == 'D')
		c->player.pos_y += c->player.dir.y * c->movspeed;
	itsanobject_ud(c, orientation);
}

void	icanmove_x_lat(t_cub3d *c, char orientation)
{
	if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'1' && orientation == 'R')
		c->player.pos_x -= c->data.plane.x * c->movspeed;
	else if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'1' && orientation == 'L')
		c->player.pos_x += c->data.plane.x * c->movspeed;
	itsanobject_rd(c, orientation);
}

void	icanmove_y_lat(t_cub3d *c, char orientation)
{
	if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'1' && orientation == 'R')
		c->player.pos_y -= c->data.plane.y * c->movspeed;
	else if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'1' && orientation == 'L')
		c->player.pos_y += c->data.plane.y * c->movspeed;
	itsanobject_rd(c, orientation);
}
