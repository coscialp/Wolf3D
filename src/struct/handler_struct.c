/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:30:07 by coscialp          #+#    #+#             */
/*   Updated: 2020/03/12 19:05:08 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

t_cub3d		*init_cub3d(char *file)
{
	t_cub3d		*c;

	if (!(c = malloc(sizeof(t_cub3d) * 1)))
	{
		msg_error("malloc");
		exit(EXIT_FAILURE);
	}
	init_data(file);
	map()->start_pos_x = -1;
	map()->start_pos_y = -1;
	player()->life = 50;
	return (c);
}

void		init_data(char *file)
{
	if (!(data()->fd = open(file, O_RDONLY)))
	{
		msg_error("open");
		exit(EXIT_FAILURE);
	}
	data()->res_x = -1;
	data()->res_y = -1;
	data()->col_floor = -1;
	data()->col_ceil = -1;
}

void		ft_free_struct(void)
{
	ft_strdel(&data()->sprite_texture);
	ft_strdel(&data()->north_texture);
	ft_strdel(&data()->south_texture);
	ft_strdel(&data()->west_texture);
	ft_strdel(&data()->east_texture);
}
