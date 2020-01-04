/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_event.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 10:52:05 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/04 18:01:52 by coscialp    ###    #+. /#+    ###.fr     */
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
	if (keycode == W || keycode == UP)
		c->move = 'U';
	else if (keycode == S || keycode == DOWN)
		c->move = 'D';
	else if (keycode == A)
		c->rotate = 'L';
	else if (keycode == D)
		c->rotate = 'R';
	return (1);
}

int		key_release(int keycode, t_cub3d *c)
{
	if (keycode == W || keycode == UP)
		c->move = 0;
	else if (keycode == S || keycode == DOWN)
		c->move = 0;
	else if (keycode == A)
		c->rotate = 0;
	else if (keycode == D)
		c->rotate = 0;
	return (1);
}
