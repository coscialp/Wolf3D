/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 12:53:46 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/03/17 17:08:25 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	move_camera(t_cub3d *c, char orientation)
{
	if (orientation == 'U')
	{
		player()->pos_x += player()->dir.x * c->movspeed;
		icanmove_x(c, orientation);
		player()->pos_y += player()->dir.y * c->movspeed;
	}
	else if (orientation == 'D')
	{
		player()->pos_x -= player()->dir.x * c->movspeed;
		icanmove_x(c, orientation);
		player()->pos_y -= player()->dir.y * c->movspeed;
	}
	icanmove_y(c, orientation);
	if (no_object(c) && orientation == 'U')
	{
		player()->pos_x -= player()->dir.x * c->movspeed;
		player()->pos_y -= player()->dir.y * c->movspeed;
	}
	else if (no_object(c) && orientation == 'D')
	{
		player()->pos_x += player()->dir.x * c->movspeed;
		player()->pos_y += player()->dir.y * c->movspeed;
	}
	change_dist_sprite(c);
}

void	move_lat_camera(t_cub3d *c, char orientation)
{
	if (orientation == 'R')
	{
		player()->pos_x += data()->plane.x * c->movspeed;
		icanmove_x_lat(c, orientation);
		player()->pos_y += data()->plane.y * c->movspeed;
	}
	else if (orientation == 'L')
	{
		player()->pos_x -= data()->plane.x * c->movspeed;
		icanmove_x_lat(c, orientation);
		player()->pos_y -= data()->plane.y * c->movspeed;
	}
	icanmove_y_lat(c, orientation);
	if (no_object(c) && orientation == 'R')
	{
		player()->pos_x -= data()->plane.x * c->movspeed;
		player()->pos_y -= data()->plane.y * c->movspeed;
	}
	else if (no_object(c) && orientation == 'L')
	{
		player()->pos_x += data()->plane.x * c->movspeed;
		player()->pos_y += data()->plane.y * c->movspeed;
	}
	change_dist_sprite(c);
}

void	rotate(t_cub3d *c, char rotate)
{
	c->old_dir.x = player()->dir.x;
	if (rotate == 'R')
	{
		player()->dir.x = player()->dir.x * cos(-c->rotspeed)
		- player()->dir.y * sin(-c->rotspeed);
		player()->dir.y = c->old_dir.x * sin(-c->rotspeed)
		+ player()->dir.y * cos(-c->rotspeed);
		c->old_plane.x =data()->plane.x;
		data()->plane.x =data()->plane.x * cos(-c->rotspeed)
		-data()->plane.y * sin(-c->rotspeed);
		data()->plane.y = c->old_plane.x * sin(-c->rotspeed)
		+data()->plane.y * cos(-c->rotspeed);
	}
	else if (rotate == 'L')
	{
		player()->dir.x = player()->dir.x * cos(c->rotspeed)
		- player()->dir.y * sin(c->rotspeed);
		player()->dir.y = c->old_dir.x * sin(c->rotspeed)
		+ player()->dir.y * cos(c->rotspeed);
		c->old_plane.x =data()->plane.x;
		data()->plane.x =data()->plane.x * cos(c->rotspeed)
		-data()->plane.y * sin(c->rotspeed);
		data()->plane.y = c->old_plane.x * sin(c->rotspeed)
		+data()->plane.y * cos(c->rotspeed);
	}
}
