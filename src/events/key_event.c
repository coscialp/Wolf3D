/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_event.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 10:52:05 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 15:15:27 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int keycode, t_cub3d *c)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(c->data.ptrwin, c->data.win);
		ft_exit_sucess(c);
	}
	if (keycode == W)
		c->move = 'U';
	else if (keycode == S)
		c->move = 'D';
	else if (keycode == A)
		c->move_lat = 'L';
	else if (keycode == D)
		c->move_lat = 'R';
	else if (keycode == LEFT)
		c->rotate = 'L';
	else if (keycode == RIGHT)
		c->rotate = 'R';
	else if (keycode == UP)
		c->move_y = 'U';
	else if (keycode == DOWN)
		c->move_y = 'D';
	else if (keycode == SPACE)
		c->movspeed = 0.15;
	return (1);
}

int		key_release(int keycode, t_cub3d *c)
{
	if (keycode == W)
		c->move = 0;
	else if (keycode == S)
		c->move = 0;
	else if (keycode == A)
		c->move_lat = 0;
	else if (keycode == D)
		c->move_lat = 0;
	else if (keycode == LEFT)
		c->rotate = 0;
	else if (keycode == RIGHT)
		c->rotate = 0;
	else if (keycode == UP)
		c->move_y = 0;
	else if (keycode == DOWN)
		c->move_y = 0;
	else if (keycode == SPACE)
		c->movspeed = 0.075;
	return (1);
}
