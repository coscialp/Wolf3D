/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_lifebar.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 11:47:25 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/03/17 22:10:33 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "cub3d.h"

void			draw_arms(t_cub3d *c, int weapons)
{
	int			color;
	int			img_x;
	int			img_y;
	t_vector	ratio;
	t_vector	tex;

	ratio.x = (double)c->tex[weapons].width / (double)(data()->res_x / 2);
	ratio.y = (double)c->tex[weapons].height / (double)(data()->res_y / 2);
	img_x = data()->res_x / 4;
	tex.x = 0;
	while (img_x < ((3 * data()->res_x) / 4) - 1)
	{
		img_y = data()->res_y / 2;
		tex.y = 0;
		while (img_y < data()->res_y)
		{
			color = c->tex[weapons].ptr[(int)tex.y * c->tex[weapons].width + (int)tex.x];
			if ((color & 0xffffff) != 0)
				c->img.ptr[img_y * data()->res_x + img_x] = color;
			img_y++;
			tex.y += ratio.y;
		}
		img_x++;
		tex.x += ratio.x;
	}
}

// void			draw_arms_shoot(t_cub3d *c)
// {
// 	int			color;
// 	int			img_x;
// 	int			img_y;
// 	t_vector	ratio;
// 	t_vector	tex;

// 	ratio.x = (double)c->tex[GUN_SHOOT].width / (double)(data()->res_x / 2);
// 	ratio.y = (double)c->tex[GUN_SHOOT].height / (double)(data()->res_y / 2);
// 	img_x = data()->res_x / 4;
// 	tex.x = 0;
// 	while (img_x < ((3 * data()->res_x) / 4) - 1)
// 	{
// 		img_y = data()->res_y / 2;
// 		tex.y = 0;
// 		while (img_y < data()->res_y)
// 		{
// 			color = c->tex[GUN_SHOOT].ptr[(int)tex.y * c->tex[GUN_SHOOT].width + (int)tex.x];
// 			if ((color & 0xffffff) != 0)
// 				c->img.ptr[img_y * data()->res_x + img_x] = color;
// 			img_y++;
// 			tex.y += ratio.y;
// 		}
// 		img_x++;
// 		tex.x += ratio.x;
// 	}
// }

// void			draw_arms_aftershoot(t_cub3d *c)
// {
// 	int			color;
// 	int			img_x;
// 	int			img_y;
// 	t_vector	ratio;
// 	t_vector	tex;

// 	ratio.x = (double)c->tex[GUN_AFTER].width / (double)(data()->res_x / 2);
// 	ratio.y = (double)c->tex[GUN_AFTER].height / (double)(data()->res_y / 2);
// 	img_x = data()->res_x / 4;
// 	tex.x = 0;
// 	while (img_x < ((3 * data()->res_x) / 4) - 1)
// 	{
// 		img_y = data()->res_y / 2;
// 		tex.y = 0;
// 		while (img_y < data()->res_y)
// 		{
// 			color = c->tex[GUN_AFTER].ptr[(int)tex.y * c->tex[GUN_AFTER].width + (int)tex.x];
// 			if ((color & 0xffffff) != 0)
// 				c->img.ptr[img_y * data()->res_x + img_x] = color;
// 			img_y++;
// 			tex.y += ratio.y;
// 		}
// 		img_x++;
// 		tex.x += ratio.x;
// 	}
// }

static int		color_lifebar(void)
{
	int		color;

	if (player()->life < 20)
		color = 0xff0000;
	else if (player()->life < 50)
		color = 0xddff00;
	else
		color = 0x00ff00;
	return (color);
}

static void		draw_stamina(t_cub3d *c, t_lifebar lb)
{
	lb.x =data()->res_y - 45;
	lb.color = 0x0000ff;
	while (lb.x <data()->res_y - 30)
	{
		lb.start =data()->res_x / 32;
		while (lb.start < (lb.width_lifebar + lb.temp_start) - lb.percentage)
		{
			c->img.ptr[lb.x *data()->res_x + lb.start] = lb.color;
			lb.start++;
		}
		lb.x++;
	}
}

void			draw_staminabar(t_cub3d *c)
{
	t_lifebar	lb;

	lb.x = data()->res_y - 50;
	lb.start = data()->res_x / 32;
	lb.temp_start = lb.start;
	lb.width_lifebar = data()->res_x / 4;
	lb.percentage = (lb.width_lifebar / 100.0) * (100.0 - (int)player()->stamina);
	while (lb.x < data()->res_y - 25)
	{
		lb.start = (data()->res_x / 32) - 5;
		while (lb.start < lb.width_lifebar + lb.temp_start + 5)
		{
			c->img.ptr[lb.x * data()->res_x + lb.start] = 0;
			lb.start++;
		}
		lb.x++;
	}
	draw_stamina(c, lb);
}

static void		draw_life(t_cub3d *c, t_lifebar lb)
{
	lb.x =data()->res_y - 75;
	lb.color = color_lifebar();
	while (lb.x <data()->res_y - 60)
	{
		lb.start =data()->res_x / 32;
		while (lb.start < (lb.width_lifebar + lb.temp_start) - lb.percentage)
		{
			c->img.ptr[lb.x *data()->res_x + lb.start] = lb.color;
			lb.start++;
		}
		lb.x++;
	}
}

void			draw_lifebar(t_cub3d *c)
{
	t_lifebar	lb;

	lb.x = data()->res_y - 80;
	lb.start = data()->res_x / 32;
	lb.temp_start = lb.start;
	lb.width_lifebar = data()->res_x / 4;
	lb.percentage = (lb.width_lifebar / 100.0) * (100.0 - player()->life);
	while (lb.x < data()->res_y - 55)
	{
		lb.start = (data()->res_x / 32) - 5;
		while (lb.start < lb.width_lifebar + lb.temp_start + 5)
		{
			c->img.ptr[lb.x * data()->res_x + lb.start] = 0;
			lb.start++;
		}
		lb.x++;
	}
	draw_life(c, lb);
}
