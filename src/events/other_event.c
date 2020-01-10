/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   other_event.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 16:13:20 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 14:15:15 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_wall(t_cub3d *c)
{
	t_pos	pos;

	pos.x = (int)(c->player.pos_x + c->player.dir.x * 1.0);
	pos.y = (int)(c->player.pos_y + c->player.dir.y * 1.0);
	if (pos.x < c->map.height - 1 && pos.x > 0 &&
	pos.y < c->map.length - 1 && pos.y > 0)
	{
		if (c->map.map_2d[pos.x][pos.y] == '1')
			c->map.map_2d[pos.x][pos.y] = '0';
		else if (c->map.map_2d[pos.x][pos.y] == '0')
			c->map.map_2d[pos.x][pos.y] = '1';
	}
}

int		close_prgm(t_cub3d *c)
{
	mlx_destroy_window(c->data.ptrwin, c->data.win);
	ft_exit_sucess(c);
	return (1);
}
