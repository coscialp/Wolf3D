/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   itsanobject.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 11:33:21 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 11:40:57 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	itsanobject_ud(t_cub3d *c, char orientation)
{
	if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'2' && orientation == 'U')
	{
		c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] = '0';
		c->player.life += 10;
	}
	else if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'2' && orientation == 'D')
	{
		c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] = '0';
		c->player.life += 10;
	}
	if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'3' && orientation == 'U')
	{
		c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] = '0';
		c->player.life -= 10;
	}
	else if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'3' && orientation == 'D')
	{
		c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] = '0';
		c->player.life -= 10;
	}
}

void	itsanobject_rd(t_cub3d *c, char orientation)
{
	if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'2' && orientation == 'R')
	{
		c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] = '0';
		c->player.life += 10;
	}
	else if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'2' && orientation == 'L')
	{
		c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] = '0';
		c->player.life += 10;
	}
	if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'3' && orientation == 'R')
	{
		c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] = '0';
		c->player.life -= 10;
	}
	else if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'3' && orientation == 'L')
	{
		c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] = '0';
		c->player.life -= 10;
	}
}
