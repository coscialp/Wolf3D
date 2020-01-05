/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 12:53:46 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/05 15:07:41 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	icanmove(t_cub3d *c, char orientation)
{
	if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'1' && orientation == 'U')
	{
		c->player.pos_x -= c->player.dir.x * c->movspeed;
		c->player.pos_y -= c->player.dir.y * c->movspeed;
	}
	else if (c->map.map_2d[(int)c->player.pos_x][(int)c->player.pos_y] ==
	'1' && orientation == 'D')
	{
		c->player.pos_x += c->player.dir.x * c->movspeed;
		c->player.pos_y += c->player.dir.y * c->movspeed;
	}
}

void	move_camera(t_cub3d *c, char orientation)
{
	if (orientation == 'U')
	{
		c->player.pos_x += c->player.dir.x * c->movspeed;
		c->player.pos_y += c->player.dir.y * c->movspeed;
	}
	else if (orientation == 'D')
	{
		c->player.pos_x -= c->player.dir.x * c->movspeed;
		c->player.pos_y -= c->player.dir.y * c->movspeed;
	}
	icanmove(c, orientation);
}

void	move_y_camera(t_cub3d *c, char orientation)
{
	if (orientation == 'U')
		c->move_cam += 20;
	else if (orientation == 'D')
		c->move_cam -= 20;
}

void	rotate(t_cub3d *c, char rotate)
{
	c->old_dir.x = c->player.dir.x;
	if (rotate == 'R')
	{
		c->player.dir.x = c->player.dir.x * cos(-c->rotspeed)
		- c->player.dir.y * sin(-c->rotspeed);
		c->player.dir.y = c->old_dir.x * sin(-c->rotspeed)
		+ c->player.dir.y * cos(-c->rotspeed);
		c->old_plane.x = c->data.plane.x;
		c->data.plane.x = c->data.plane.x * cos(-c->rotspeed)
		- c->data.plane.y * sin(-c->rotspeed);
		c->data.plane.y = c->old_plane.x * sin(-c->rotspeed)
		+ c->data.plane.y * cos(-c->rotspeed);
	}
	else if (rotate == 'L')
	{
		c->player.dir.x = c->player.dir.x * cos(c->rotspeed)
		- c->player.dir.y * sin(c->rotspeed);
		c->player.dir.y = c->old_dir.x * sin(c->rotspeed)
		+ c->player.dir.y * cos(c->rotspeed);
		c->old_plane.x = c->data.plane.x;
		c->data.plane.x = c->data.plane.x * cos(c->rotspeed)
		- c->data.plane.y * sin(c->rotspeed);
		c->data.plane.y = c->old_plane.x * sin(c->rotspeed)
		+ c->data.plane.y * cos(c->rotspeed);
	}
}
