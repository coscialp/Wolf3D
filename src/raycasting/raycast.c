/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycast.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 18:10:50 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 18:40:53 by coscialp    ###    #+. /#+    ###.fr     */
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

void	throwing_ray(t_cub3d *c, t_vector ray)
{
	init_step(c, ray);
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

void	raycast_texture(t_vector ray, t_cub3d *c, double wall, int x)
{
	if (c->draw_end >= c->data.res_y)
		c->draw_end = c->data.res_y - 1;
	if (c->side == 0)
		c->wall_pos = c->player.pos_y + wall * ray.y;
	else
		c->wall_pos = c->player.pos_x + wall * ray.x;
	c->direction = wall_orientation(ray, c);
	c->wall_pos -= (int)c->wall_pos;
	c->tex_x = (int)(c->wall_pos * c->tex[c->direction].width);
	if (c->side == 0 && ray.x > 0)
		c->tex_x = c->tex[c->direction].width - c->tex_x - 1;
	if (c->side == 1 && ray.y < 0)
		c->tex_x = c->tex[c->direction].width - c->tex_x - 1;
	c->step = 1.0 * c->tex[c->direction].height / c->height_draw;
	c->tex_pos = ((c->draw_start - c->move_cam)
	- c->data.res_y / 2 + c->height_draw / 2) * c->step;
	c->zbuffer[x] = wall;
}

void	secu_draw(int *draw, t_cub3d *c)
{
	if (*draw < 0)
		*draw = 0;
	else if (*draw > c->data.res_y)
		*draw = c->data.res_y;
}

int		raycast(t_cub3d *c)
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
		throwing_ray(c, ray);
		if (c->side == 0)
			wall = (c->map_x - c->player.pos_x + (1 - c->step_x) / 2) / ray.x;
		else
			wall = (c->map_y - c->player.pos_y + (1 - c->step_y) / 2) / ray.y;
		c->height_draw = (c->data.res_y / wall);
		c->draw_start = -(c->height_draw) / 2 + c->data.res_y / 2 + c->move_cam;
		secu_draw(&c->draw_start, c);
		c->draw_end = (c->height_draw) / 2 + c->data.res_y / 2 + c->move_cam;
		secu_draw(&c->draw_end, c);
		raycast_texture(ray, c, wall, x);
		draw(c, x);
	}
	return (sprite_casting(c));
}
