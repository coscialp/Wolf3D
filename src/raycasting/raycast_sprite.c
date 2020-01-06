/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycast_sprite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 13:10:17 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 18:42:48 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sprite(t_cub3d *c)
{
	int		i;
	int		n;
	int		j;
	double	tmp;

	n = 0;
	i = 0;
	tmp = c->sprite_dist[0];
	while (n < c->data.num_sprite)
	{
		j = 0;
		while (j < c->data.num_sprite)
		{
			if (c->sprite_dist[j] > tmp)
			{
				tmp = c->sprite_dist[j];
				c->sprite_order[i] = j;
				i++;
			}
			j++;
		}
		n++;
	}
}

int		sprite_casting(t_cub3d *c)
{
	int	i;

	i = 0;
	while (i < c->data.num_sprite)
	{
		c->sprite_order[i] = 0;
		c->sprite_dist[i] = (c->player.pos_x - c->sprite[i].x) * (c->player.pos_x - c->sprite[i].x) +
		(c->player.pos_y - c->sprite[i].y) * (c->player.pos_y - c->sprite[i].y);
		i++;
	}
	sort_sprite(c);
	i = 0;
	while (i < c->data.num_sprite)
	{
		c->sprite_pos.x = c->sprite[c->sprite_order[i]].x - c->player.pos_x;
		c->sprite_pos.y = c->sprite[c->sprite_order[i]].y - c->player.pos_y;
		c->inv_correc = 1.0 / (c->data.plane.x * c->player.dir.y - c->player.dir.x * c->data.plane.y);
		c->transform.x = c->inv_correc * (c->player.dir.y * c->sprite_pos.x - c->player.dir.x * c->sprite_pos.y);
		c->transform.y = c->inv_correc * (-c->data.plane.y * c->sprite_pos.x + c->data.plane.x * c->sprite_pos.y);
		c->sprite_screen = (int)((c->data.res_x / 2) * (1 + c->transform.x / c->transform.y));
		c->sprite_height = ft_abs((int)(c->data.res_x / (c->transform.y)));
		c->sprite_start.y = -c->sprite_height / 2 + c->data.res_x / 2;
		if (c->sprite_start.y < 0)
			c->sprite_start.y = 0;
		c->sprite_end.y = c->sprite_height / 2 + c->data.res_x / 2;
		if (c->sprite_end.y >= c->data.res_x)
			c->sprite_end.y = c->data.res_x - 1;
		c->sprite_width = ft_abs((int)(c->data.res_x / (c->transform.y)));
		c->sprite_start.x = -c->sprite_width / 2 + c->sprite_screen;
		if (c->sprite_start.x < 0)
			c->sprite_start.x = 0;
		c->sprite_end.x = c->sprite_width / 2 + c->sprite_screen;
		if (c->sprite_end.x >= c->data.res_x)
			c->sprite_end.x = c->data.res_x - 1;
		draw_sprite(c);
		i++;
	}
	return (0);
}

void	raycast_sprite(t_cub3d *c)
{
	if (!(c->zbuffer = malloc(sizeof(double) * c->data.res_x)))
		ft_exit(c);
	if (!(c->sprite_order = malloc(sizeof(int) * c->data.num_sprite)))
		ft_exit(c);
	if (!(c->sprite_dist = malloc(sizeof(double) * c->data.num_sprite)))
		ft_exit(c);
}

int		wall_orientation(t_vector ray, t_cub3d *c)
{
	if (c->side)
		return (ray.y < 0 ? 3 : 2);
	return (ray.x < 0 ? 0 : 1);
}
