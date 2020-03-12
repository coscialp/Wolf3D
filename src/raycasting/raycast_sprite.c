/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:10:17 by coscialp          #+#    #+#             */
/*   Updated: 2020/03/12 19:55:24 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

static void	sort_sprite(t_cub3d *c)
{
	int			i;
	t_sprite	dbuf;

	i = 0;
	while (i < data()->num_sprite - 1)
	{
		i++;
		if (c->sprite[i - 1].dist < c->sprite[i].dist)
		{
			dbuf = c->sprite[i - 1];
			c->sprite[i - 1] = c->sprite[i];
			c->sprite[i] = dbuf;
			i = 0;
		}
	}
}

static void	math_sprite(t_cub3d *c, int i)
{
	c->sprite_pos.x = c->sprite[i].x - player()->pos_x;
	c->sprite_pos.y = c->sprite[i].y - player()->pos_y;
	c->inv_correc = 1.0 / ((data()->plane.x * player()->dir.y)
	- (player()->dir.x * data()->plane.y));
	c->transform.x = c->inv_correc * ((player()->dir.y * c->sprite_pos.x)
	- (player()->dir.x * c->sprite_pos.y));
	c->transform.y = c->inv_correc * ((-data()->plane.y * c->sprite_pos.x)
	+ (data()->plane.x * c->sprite_pos.y));
	c->sprite_screen = (int)((data()->res_x / 2) *
	(1 + c->transform.x / c->transform.y));
	c->sprite_height = ft_abs((int)(data()->res_y / (c->transform.y)));
	c->sprite_start.y = (-c->sprite_height / 2 +
	data()->res_y / 2);
	if (c->sprite_start.y < 0)
		c->sprite_start.y = 0;
	c->sprite_end.y = (c->sprite_height / 2 + data()->res_y / 2);
	if (c->sprite_end.y >= data()->res_y)
		c->sprite_end.y = data()->res_y - 1;
	c->sprite_width = ft_abs((int)(data()->res_y / (c->transform.y)));
}

int			sprite_casting(t_cub3d *c)
{
	int	i;

	i = 0;
	while (i < data()->num_sprite)
	{
		c->sprite[i].dist = (player()->pos_x - c->sprite[i].x) *
		(player()->pos_x - c->sprite[i].x) +
		(player()->pos_y - c->sprite[i].y) * (player()->pos_y - c->sprite[i].y);
		i++;
	}
	sort_sprite(c);
	i = -1;
	while (++i < data()->num_sprite)
	{
		math_sprite(c, i);
		c->sprite_start.x = -c->sprite_width / 2 + c->sprite_screen;
		if (c->sprite_start.x < 0)
			c->sprite_start.x = 0;
		c->sprite_end.x = c->sprite_width / 2 + c->sprite_screen;
		if (c->sprite_end.x >= data()->res_x)
			c->sprite_end.x = data()->res_x - 1;
		draw_sprite(c, c->sprite[i].type);
	}
	return (0);
}

int			wall_orientation(t_vector ray, t_cub3d *c)
{
	if (c->side)
		return (ray.y < 0 ? 2 : 3);
	return (ray.x < 0 ? 1 : 0);
}
