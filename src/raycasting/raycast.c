/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycast.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 18:10:50 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 15:56:15 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	init_step(t_cub3d *c, t_vector ray)
{
	c->map_x = (int)c->player.pos_x;
	c->map_y = (int)c->player.pos_y;
	c->delta_dist.x = fabs(1 / ray.x);
	c->delta_dist.y = fabs(1 / ray.y);
	c->hit = 0;
	if (ray.x < 0)
	{
		c->step_x = -1;
		c->side_dist.x = (c->player.pos_x - c->map_x) * c->delta_dist.x;
	}
	else
	{
		c->step_x = 1;
		c->side_dist.x = (c->map_x + 1.0 - c->player.pos_x) * c->delta_dist.x;
	}
	if (ray.y < 0)
	{
		c->step_y = -1;
		c->side_dist.y = (c->player.pos_y - c->map_y) * c->delta_dist.y;
	}
	else
	{
		c->step_y = 1;
		c->side_dist.y = (c->map_y + 1.0 - c->player.pos_y) * c->delta_dist.y;
	}
}

void	throwing_ray(t_cub3d *c)
{
	while (c->hit == 0)
	{
		if (c->side_dist.x < c->side_dist.y)
		{
			c->side_dist.x += c->delta_dist.x;
			c->map_x += c->step_x;
			c->side = 0;
		}
		else
		{
			c->side_dist.y += c->delta_dist.y;
			c->map_y += c->step_y;
			c->side = 1;
		}
		if (c->map.map_2d[c->map_x][c->map_y] == '1')
			c->hit = 1;
	}
}

void	draw_wall(t_cub3d *c, int x)
{
	int		color;
	int		y;

	y = c->draw_start;
	color = c->side == 1 ? 0x00ff00 / 2 : 0x00ff00;
	while (y < c->draw_end)
	{
		mlx_pixel_put(c->data.ptrwin, c->data.win, x, y, color);
		y++;
	}
}

void	draw_floor(t_cub3d *c, int x)
{
	int		y;

	y = c->draw_end;
	while (y < c->data.res_y)
	{
		mlx_pixel_put(c->data.ptrwin, c->data.win, x, y, c->data.col_floor);
		y++;
	}
}

void	draw_ceilling(t_cub3d *c, int x)
{
	int		y;

	y = 0;
	while (y < c->draw_start)
	{
		mlx_pixel_put(c->data.ptrwin, c->data.win, x, y, c->data.col_ceil);
		y++;
	}
}

void	draw(t_cub3d *c, int x)
{
	draw_wall(c, x);
	draw_floor(c, x);
	draw_ceilling(c, x);
}

void	raycast(t_cub3d *c)
{
	int			x;
	double		wall;
	t_vector	ray;

	x = -1;
	while (++x < c->data.res_x)
	{
		c->cam_x = 2.0 * x / (double)c->data.res_x - 1.0;
		ray.x = c->player.dir.x + c->data.plane.x * c->cam_x;
		ray.y = c->player.dir.y + c->data.plane.y * c->cam_x;
		init_step(c, ray);
		throwing_ray(c);
		if (c->side == 0)
			wall = (c->map_x - c->player.pos_x + (1 - c->step_x) / 2) / ray.x;
		else
			wall = (c->map_y - c->player.pos_y + (1 - c->step_y) / 2) / ray.y;
		c->height_draw = (c->data.res_y / wall);
		c->draw_start = -c->height_draw / 2 + c->data.res_y / 2;
		if (c->draw_start < 0)
			c->draw_start = 0;
		c->draw_end = c->height_draw / 2 + c->data.res_y / 2;
		if (c->draw_end >= c->data.res_y)
			c->draw_end = c->data.res_y - 1;
		draw(c, x);
	}
}
