/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycast.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 18:10:50 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/03/18 17:41:49 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	init_step(t_cub3d *c, t_vector ray)
{
	c->map_x = (int)player()->pos_x;
	c->map_y = (int)player()->pos_y;
	c->delta_dist.x = fabs(1 / ray.x);
	c->delta_dist.y = fabs(1 / ray.y);
	c->hit = 0;
	if (ray.x < 0)
	{
		c->step_x = -1;
		c->side_dist.x = (player()->pos_x - c->map_x) * c->delta_dist.x;
	}
	else
	{
		c->step_x = 1;
		c->side_dist.x = (c->map_x + 1.0 - player()->pos_x) * c->delta_dist.x;
	}
	if (ray.y < 0)
	{
		c->step_y = -1;
		c->side_dist.y = (player()->pos_y - c->map_y) * c->delta_dist.y;
	}
	else
	{
		c->step_y = 1;
		c->side_dist.y = (c->map_y + 1.0 - player()->pos_y) * c->delta_dist.y;
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
		if (map()->map_2d[c->map_x][c->map_y] == '1')
			c->hit = 1;
		if (map()->map_2d[c->map_x][c->map_y] == '5')
			c->hit = 2;
		if (map()->map_2d[c->map_x][c->map_y] == 'a')
			c->hit = 'a' - 51;
	}
}

void	raycast_texture(t_vector ray, t_cub3d *c, double wall, int x)
{
	if (c->draw_end >= data()->res_y)
		c->draw_end = data()->res_y - 1;
	if (c->side == 0)
		c->wall_pos = player()->pos_y + wall * ray.y;
	else
		c->wall_pos = player()->pos_x + wall * ray.x;
	c->direction = wall_orientation(ray, c);
	c->wall_pos -= (int)c->wall_pos;
	c->tex_x = (int)(c->wall_pos * c->tex[c->direction].width);
	if (c->side == 0 && ray.x > 0)
		c->tex_x = c->tex[c->direction].width - c->tex_x - 1;
	if (c->side == 1 && ray.y < 0)
		c->tex_x = c->tex[c->direction].width - c->tex_x - 1;
	c->step = 1.0 * c->tex[c->direction].height / c->height_draw;
	c->tex_pos = (c->draw_start
	- data()->res_y / 2 + c->height_draw / 2) * c->step;
	c->zbuffer[x] = wall;
}

void	secu_draw(int *draw)
{
	if (*draw < 0)
		*draw = 0;
	else if (*draw > data()->res_y)
		*draw = data()->res_y;
}


int		raycast(t_cub3d *c)
{
	int			x;
	double		wall;
	t_vector	ray;

	x = -1;
	while (++x < data()->res_x)
	{
		c->cam_x = 2.0 * x / (double)data()->res_x - 1.0;
		ray.x = player()->dir.x + data()->plane.x * c->cam_x;
		ray.y = player()->dir.y + data()->plane.y * c->cam_x;
		throwing_ray(c, ray);
		if (c->side == 0)
			wall = (c->map_x - player()->pos_x + (1 - c->step_x) / 2) / ray.x;
		else
			wall = (c->map_y - player()->pos_y + (1 - c->step_y) / 2) / ray.y;
		c->height_draw = (data()->res_y / wall);
		c->draw_start = -(c->height_draw) / 2 + data()->res_y / 2;
		secu_draw(&c->draw_start);
		c->draw_end = (c->height_draw) / 2 + data()->res_y / 2;
		secu_draw(&c->draw_end);
		raycast_texture(ray, c, wall, x);
		draw(c, x);
	}
	return (sprite_casting(c));
}

void	throwing_second_ray(t_cub3d *c, t_vector ray)
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
		if (is_wall(map()->map_2d, c->map_x, c->map_y))
			c->hit = 2;
		if (map()->map_2d[c->map_x][c->map_y] >= '6' && map()->map_2d[c->map_x][c->map_y] < '6' + 8)
			c->hit = map()->map_2d[c->map_x][c->map_y] - 51;
	}
}

void	draw_second_wall(t_cub3d *c, int x)
{
	int		y;
	double	coef;
	t_color	color;

	y = c->draw_start;
	while (y < c->draw_end)
	{
		c->tex_y = (int)c->tex_pos & (c->tex[c->direction].height - 1);
		c->tex_pos += c->step;
		color.color = c->tex[c->direction].ptr[c->tex_y *
		c->tex[c->direction].width + c->tex_x];
		coef = c->zbuffer[x] < 25 ? 1 - c->zbuffer[x] / 25 : 0;
		if (c->side == 0)
		{
			color.rgba.r *= 0.7;
			color.rgba.g *= 0.7;
			color.rgba.b *= 0.7;
		}
		color.rgba.r *= coef;
		color.rgba.g *= coef;
		color.rgba.b *= coef;
		if ((color.color & 0xfffff) != 0)
			c->img.ptr[y * data()->res_x + x] = color.color;
		y++;
	}
}

void	second_raycast(t_cub3d *c)
{
	int			x;
	double		wall;
	t_vector	ray;

	x = -1;
	while (++x < data()->res_x)
	{
		c->cam_x = 2.0 * x / (double)data()->res_x - 1.0;
		ray.x = player()->dir.x + data()->plane.x * c->cam_x;
		ray.y = player()->dir.y + data()->plane.y * c->cam_x;
		throwing_second_ray(c, ray);
		if (c->hit == 2)
			continue ;
		if (c->side == 0)
			wall = (c->map_x - player()->pos_x + (1 - c->step_x) / 2) / ray.x;
		else
			wall = (c->map_y - player()->pos_y + (1 - c->step_y) / 2) / ray.y;
		c->height_draw = (data()->res_y / wall);
		c->draw_start = -(c->height_draw) / 2 + data()->res_y / 2;
		secu_draw(&c->draw_start);
		c->draw_end = (c->height_draw) / 2 + data()->res_y / 2;
		secu_draw(&c->draw_end);
		raycast_texture(ray, c, wall, x);
		draw_second_wall(c, x);
	}
}