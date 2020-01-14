/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 12:53:46 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 14:03:36 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	move_camera(t_cub3d *c, char orientation)
{
	if (orientation == 'U')
	{
		c->player.pos_x += c->player.dir.x * c->movspeed;
		icanmove_x(c, orientation);
		c->player.pos_y += c->player.dir.y * c->movspeed;
	}
	else if (orientation == 'D')
	{
		c->player.pos_x -= c->player.dir.x * c->movspeed;
		icanmove_x(c, orientation);
		c->player.pos_y -= c->player.dir.y * c->movspeed;
	}
	icanmove_y(c, orientation);
}

void	move_lat_camera(t_cub3d *c, char orientation)
{
	if (orientation == 'R')
	{
		c->player.pos_x += c->data.plane.x * c->movspeed;
		icanmove_x_lat(c, orientation);
		c->player.pos_y += c->data.plane.y * c->movspeed;
	}
	else if (orientation == 'L')
	{
		c->player.pos_x -= c->data.plane.x * c->movspeed;
		icanmove_x_lat(c, orientation);
		c->player.pos_y -= c->data.plane.y * c->movspeed;
	}
	icanmove_y_lat(c, orientation);
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
