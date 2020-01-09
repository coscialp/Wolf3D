/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_lifebar.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 11:47:25 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 12:05:50 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

static int		color_lifebar(t_cub3d *c)
{
	int		color;

	if (c->player.life < 20)
		color = 0xff0000;
	else if (c->player.life < 50)
		color = 0xddff00;
	else
		color = 0x00ff00;
	return (color);
}

static void		draw_life(t_cub3d *c, t_lifebar lb)
{
	lb.x = c->data.res_y - 50;
	lb.color = color_lifebar(c);
	while (lb.x < c->data.res_y - 10)
	{
		lb.start = c->data.res_x / 4;
		while (lb.start < (lb.width_lifebar + lb.temp_start) - lb.percentage)
		{
			c->img.ptr[lb.x * c->data.res_x + lb.start] = lb.color;
			lb.start++;
		}
		lb.x++;
	}
}

void			draw_lifebar(t_cub3d *c)
{
	t_lifebar	lb;

	lb.x = c->data.res_y - 60;
	lb.start = c->data.res_x / 4;
	lb.temp_start = lb.start;
	lb.width_lifebar = c->data.res_x / 2;
	lb.percentage = (lb.width_lifebar / 100.0) * (100.0 - c->player.life);
	while (lb.x < c->data.res_y)
	{
		lb.start = (c->data.res_x / 4) - 10;
		while (lb.start < lb.width_lifebar + lb.temp_start + 10)
		{
			c->img.ptr[lb.x * c->data.res_x + lb.start] = 0;
			lb.start++;
		}
		lb.x++;
	}
	draw_life(c, lb);
}
