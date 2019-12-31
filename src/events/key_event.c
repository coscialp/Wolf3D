/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_event.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 10:52:05 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 13:58:08 by coscialp    ###    #+. /#+    ###.fr     */
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
	else
		ft_dprintf(1, "keycode:\t%d\n", keycode);
	return (1);
}
