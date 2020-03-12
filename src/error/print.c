/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:31:39 by coscialp          #+#    #+#             */
/*   Updated: 2020/03/12 19:10:50 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	print_params(void)
{
	ft_dprintf(2, "res_x:\t%d\nres_y:\t%d\n", data()->res_x, data()->res_y);
	ft_dprintf(2, "south_texture:\t|%s|\n", data()->south_texture);
	ft_dprintf(2, "north_texture:\t|%s|\n", data()->north_texture);
	ft_dprintf(2, "west_texture:\t|%s|\n", data()->west_texture);
	ft_dprintf(2, "east_texture:\t|%s|\n", data()->east_texture);
	ft_dprintf(2, "sprite_texture:\t|%s|\n", data()->sprite_texture);
	ft_dprintf(2, "color_floor:\t%d\n", data()->col_floor);
	ft_dprintf(2, "color_sky:\t%d\n\n", data()->col_ceil);
	ft_putstr_tab(map()->map_2d);
	ft_dprintf(2, "pos_y:\t\t%f\n", player()->pos_y);
	ft_dprintf(2, "pos_x:\t\t%f\n", player()->pos_x);
	ft_dprintf(2, "dirX:\t\t%f\n", player()->dir.x);
	ft_dprintf(2, "dirY:\t\t%f\n", player()->dir.y);
}
