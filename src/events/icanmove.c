/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   icanmove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:29:36 by coscialp          #+#    #+#             */
/*   Updated: 2020/03/12 19:13:49 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	icanmove_x(t_cub3d *c, char orientation)
{
	if ((map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] ==
	'1' || map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] ==
	'4') && orientation == 'U')
		player()->pos_x -= player()->dir.x * c->movspeed;
	else if ((map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] ==
	'1' || map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] ==
	'4') && orientation == 'D')
		player()->pos_x += player()->dir.x * c->movspeed;
	itsanobject_ud(orientation);
}

void	icanmove_y(t_cub3d *c, char orientation)
{
	if ((map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] ==
	'1' || map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] ==
	'4') && orientation == 'U')
		player()->pos_y -= player()->dir.y * c->movspeed;
	else if ((map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] ==
	'1' || map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] ==
	'4') && orientation == 'D')
		player()->pos_y += player()->dir.y * c->movspeed;
	itsanobject_ud(orientation);
}

void	icanmove_x_lat(t_cub3d *c, char orientation)
{
	if ((map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] ==
	'1' || map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] ==
	'4') && orientation == 'R')
		player()->pos_x -= data()->plane.x * c->movspeed;
	else if ((map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] ==
	'1' || map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] ==
	'4') && orientation == 'L')
		player()->pos_x += data()->plane.x * c->movspeed;
	itsanobject_rd(orientation);
}

void	icanmove_y_lat(t_cub3d *c, char orientation)
{
	if ((map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] ==
	'1' || map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] ==
	'4') && orientation == 'R')
		player()->pos_y -= data()->plane.y * c->movspeed;
	else if ((map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] ==
	'1' || map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] ==
	'4') && orientation == 'L')
		player()->pos_y += data()->plane.y * c->movspeed;
	itsanobject_rd(orientation);
}
