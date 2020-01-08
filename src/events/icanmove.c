/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   icanmove.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 15:29:36 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 22:25:07 by coscialp    ###    #+. /#+    ###.fr     */
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
	if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'2' && orientation == 'U')
	{
		c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] = '0';
		c->player.pos_x -= c->player.dir.x * c->movspeed;
		c->player.life += 10;
	}
	else if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'2' && orientation == 'D')
	{
		c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] = '0';
		c->player.pos_x += c->player.dir.x * c->movspeed;
		c->player.life += 10;
	}
		if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'3' && orientation == 'U')
	{
		c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] = '0';
		c->player.pos_x -= c->player.dir.x * c->movspeed;
		c->player.life -= 10;
	}
	else if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'3' && orientation == 'D')
	{
		c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] = '0';
		c->player.pos_x += c->player.dir.x * c->movspeed;
		c->player.life -= 10;
	}
}

void	icanmove_y(t_cub3d *c, char orientation)
{
	if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'1' && orientation == 'U')
		c->player.pos_y -= c->player.dir.y * c->movspeed;
	else if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'1' && orientation == 'D')
		c->player.pos_y += c->player.dir.y * c->movspeed;
	if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'2' && orientation == 'U')
	{
		c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] = '0';
		c->player.pos_y -= c->player.dir.y * c->movspeed;
		c->player.life += 10;
	}
	else if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'2' && orientation == 'D')
	{
		c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] = '0';
		c->player.pos_y += c->player.dir.y * c->movspeed;
		c->player.life += 10;
	}
	if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'3' && orientation == 'U')
	{
		c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] = '0';
		c->player.pos_y -= c->player.dir.y * c->movspeed;
		c->player.life -= 10;
	}
	else if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'3' && orientation == 'D')
	{
		c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] = '0';
		c->player.pos_y += c->player.dir.y * c->movspeed;
		c->player.life -= 10;
	}
}

void	icanmove_x_lat(t_cub3d *c, char orientation)
{
	if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'1' && orientation == 'R')
		c->player.pos_x -= c->data.plane.x * c->movspeed;
	else if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'1' && orientation == 'L')
		c->player.pos_x += c->data.plane.x * c->movspeed;
	if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'2' && orientation == 'R')
	{
		c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] = '0';
		c->player.pos_x -= c->data.plane.x * c->movspeed;
		c->player.life += 10;
	}
	else if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'2' && orientation == 'L')
	{
		c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] = '0';
		c->player.pos_x += c->data.plane.x * c->movspeed;
		c->player.life += 10;
	}
	if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'3' && orientation == 'R')
	{
		c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] = '0';
		c->player.pos_x -= c->data.plane.x * c->movspeed;
		c->player.life -= 10;
	}
	else if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'3' && orientation == 'L')
	{
		c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] = '0';
		c->player.pos_x += c->data.plane.x * c->movspeed;
		c->player.life -= 10;
	}
}

void	icanmove_y_lat(t_cub3d *c, char orientation)
{
	if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'1' && orientation == 'R')
		c->player.pos_y -= c->data.plane.y * c->movspeed;
	else if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'1' && orientation == 'L')
		c->player.pos_y += c->data.plane.y * c->movspeed;
	if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'2' && orientation == 'R')
	{
		c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] = '0';
		c->player.pos_y -= c->data.plane.y * c->movspeed;
		c->player.life += 10;
	}
	else if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'2' && orientation == 'L')
	{
		c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] = '0';
		c->player.pos_y += c->data.plane.y * c->movspeed;
		c->player.life += 10;
	}
	if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'3' && orientation == 'R')
	{
		c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] = '0';
		c->player.pos_y -= c->data.plane.y * c->movspeed;
		c->player.life -= 10;
	}
	else if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'3' && orientation == 'L')
	{
		c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] = '0';
		c->player.pos_y += c->data.plane.y * c->movspeed;
		c->player.life -= 10;
	}
}
