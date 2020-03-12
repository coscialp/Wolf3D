/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 10:52:05 by coscialp          #+#    #+#             */
/*   Updated: 2020/03/12 18:44:09 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int		key_press(int keycode, t_cub3d *c)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data()->ptrwin, data()->win);
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
	else if (keycode == SHIFT)
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
	else if (keycode == SHIFT)
		c->movspeed = 0.075;
	return (1);
}
