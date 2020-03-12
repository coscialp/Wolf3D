/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:13:20 by coscialp          #+#    #+#             */
/*   Updated: 2020/03/12 19:11:46 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	destroy_wall(void)
{
	t_pos	pos;

	pos.x = (int)(player()->pos_x + player()->dir.x * 1.0);
	pos.y = (int)(player()->pos_y + player()->dir.y * 1.0);
	if (pos.x < map()->height && pos.x > 0 &&
	pos.y < map()->length - 1 && pos.y > 0)
	{
		if (map()->map_2d[pos.x][pos.y] == '1')
			map()->map_2d[pos.x][pos.y] = '0';
		else if (map()->map_2d[pos.x][pos.y] == '0')
			map()->map_2d[pos.x][pos.y] = '1';
	}
}

int		close_prgm(t_cub3d *c)
{
	mlx_destroy_window(data()->ptrwin, data()->win);
	ft_exit_sucess(c);
	return (1);
}
