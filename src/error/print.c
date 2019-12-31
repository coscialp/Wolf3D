/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 18:31:39 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 13:57:51 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	print_params(t_cub3d *c)
{
	ft_dprintf(2, "res_x:\t%d\nres_y:\t%d\n", c->data.res_x, c->data.res_y);
	ft_dprintf(2, "south_texture:\t|%s|\n", c->data.south_texture);
	ft_dprintf(2, "north_texture:\t|%s|\n", c->data.north_texture);
	ft_dprintf(2, "west_texture:\t|%s|\n", c->data.west_texture);
	ft_dprintf(2, "east_texture:\t|%s|\n", c->data.east_texture);
	ft_dprintf(2, "sprite_texture:\t|%s|\n", c->data.sprite_texture);
	ft_dprintf(2, "color_floor:\t%d\n", c->data.col_floor);
	ft_dprintf(2, "color_sky:\t%d\n\n", c->data.col_ceil);
	ft_putstr_tab(c->map.map_2d);
	ft_dprintf(2, "pos_y:\t\t%f\n", c->player.pos_y);
	ft_dprintf(2, "pos_x:\t\t%f\n", c->player.pos_x);
	ft_dprintf(2, "dirX:\t\t%f\n", c->player.dir.x);
	ft_dprintf(2, "dirY:\t\t%f\n", c->player.dir.y);
}
