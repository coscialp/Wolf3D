/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itsanobject.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:33:21 by coscialp          #+#    #+#             */
/*   Updated: 2020/03/12 19:13:15 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	itsanobject_ud(char orientation)
{
	if (map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] ==
	'2' && orientation == 'U')
	{
		map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] = '0';
		player()->life += 10;
	}
	else if (map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] ==
	'2' && orientation == 'D')
	{
		map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] = '0';
		player()->life += 10;
	}
	if (map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] ==
	'3' && orientation == 'U')
	{
		map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] = '0';
		player()->life -= 10;
	}
	else if (map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] ==
	'3' && orientation == 'D')
	{
		map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] = '0';
		player()->life -= 10;
	}
}

void	itsanobject_rd(char orientation)
{
	if (map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] ==
	'2' && orientation == 'R')
	{
		map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] = '0';
		player()->life += 10;
	}
	else if (map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] ==
	'2' && orientation == 'L')
	{
		map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] = '0';
		player()->life += 10;
	}
	if (map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] ==
	'3' && orientation == 'R')
	{
		map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] = '0';
		player()->life -= 10;
	}
	else if (map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] ==
	'3' && orientation == 'L')
	{
		map()->map_2d[(int)player()->pos_x][(int)player()->pos_y] = '0';
		player()->life -= 10;
	}
}
