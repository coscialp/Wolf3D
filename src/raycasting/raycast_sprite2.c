/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycast_sprite2.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 19:03:23 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 11:43:38 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sprite2(t_cub3d *c)
{
	int		i;
	int		buff;
	double	dbuf;

	i = 0;
	while (i < c->data.num_sprite2 - 1)
	{
		i++;
		if (c->sprite_dist2[i - 1] < c->sprite_dist2[i])
		{
			dbuf = c->sprite_dist2[i - 1];
			c->sprite_dist2[i - 1] = c->sprite_dist2[i];
			c->sprite_dist2[i] = dbuf;
			buff = c->sprite_order2[i - 1];
			c->sprite_order2[i - 1] = c->sprite_order2[i];
			c->sprite_order2[i] = buff;
			i = 0;
		}
	}
}

void	math_sprite2(t_cub3d *c, int i)
{
	c->sprite_pos.x = c->sprite2[c->sprite_order2[i]].x - c->player.pos_x;
	c->sprite_pos.y = c->sprite2[c->sprite_order2[i]].y - c->player.pos_y;
	c->inv_correc = 1.0 / ((c->data.plane.x * c->player.dir.y)
	- (c->player.dir.x * c->data.plane.y));
	c->transform.x = c->inv_correc * ((c->player.dir.y * c->sprite_pos.x)
	- (c->player.dir.x * c->sprite_pos.y));
	c->transform.y = c->inv_correc * ((-c->data.plane.y * c->sprite_pos.x)
	+ (c->data.plane.x * c->sprite_pos.y));
	c->sprite_screen = (int)((c->data.res_x / 2) *
	(1 + c->transform.x / c->transform.y));
	c->sprite_height = ft_abs((int)(c->data.res_y / (c->transform.y)));
	c->sprite_start.y = (-c->sprite_height / 2 +
	c->data.res_y / 2) + c->move_cam;
	if (c->sprite_start.y < 0)
		c->sprite_start.y = 0;
	c->sprite_end.y = (c->sprite_height / 2 + c->data.res_y / 2) + c->move_cam;
	if (c->sprite_end.y >= c->data.res_y)
		c->sprite_end.y = c->data.res_y - 1;
	c->sprite_width = ft_abs((int)(c->data.res_y / (c->transform.y)));
}

int		sprite_casting2(t_cub3d *c, int i)
{
	while (i < c->data.num_sprite2)
	{
		c->sprite_order2[i] = i;
		c->sprite_dist2[i] = (c->player.pos_x - c->sprite2[i].x) *
		(c->player.pos_x - c->sprite2[i].x) +
		(c->player.pos_y - c->sprite2[i].y) *
		(c->player.pos_y - c->sprite2[i].y);
		i++;
	}
	sort_sprite2(c);
	i = -1;
	while (++i < c->data.num_sprite2)
	{
		math_sprite2(c, i);
		c->sprite_start.x = -c->sprite_width / 2 + c->sprite_screen;
		if (c->sprite_start.x < 0)
			c->sprite_start.x = 0;
		c->sprite_end.x = c->sprite_width / 2 + c->sprite_screen;
		if (c->sprite_end.x >= c->data.res_x)
			c->sprite_end.x = c->data.res_x - 1;
		draw_sprite(c, 7);
	}
	return (0);
}

void	raycast_sprite2(t_cub3d *c)
{
	if (!(c->zbuffer2 = malloc(sizeof(double) * c->data.res_x)))
		ft_exit(c);
	if (!(c->sprite_order2 = malloc(sizeof(int) * c->data.num_sprite2)))
		ft_exit(c);
	if (!(c->sprite_dist2 = malloc(sizeof(double) * c->data.num_sprite2)))
		ft_exit(c);
}
