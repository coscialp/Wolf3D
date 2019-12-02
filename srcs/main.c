/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 12:37:24 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 14:09:54 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int ac, char **av)
{
	int		fd;
	t_data	*data;
	t_map	*map;
	t_color	*color;

	if (ac == 2)
	{
		if (!(data = init_data()))
			return (msg_error("malloc"));
		if (!(map = init_map()))
			return (msg_error("malloc"));
		if (!(color = init_color()))
			return (msg_error("malloc"));
		if (!(fd = open(av[ac - 1], O_RDONLY)))
			return (msg_error("open"));
		if (parsing_core(fd, data, map, color) == -1)
			return (-1);
		ft_dprintf(1, "res_x:\t%d\nres_y:\t%d\n", data->res_x, data->res_y);
		ft_dprintf(1, "south_texture:\t|%s|\nnorth_texture:\t|%s|\nwest_texture:\t|%s|\neast_texture:\t|%s|\nsprite_texture:\t|%s|\n", data->south_texture, data->north_texture, data->west_texture, data->east_texture, data->sprite_texture);
		ft_dprintf(1, "color_floor:\t%d\ncolor_sky:\t%d\n", data->color_floor, data->color_sky);
		ft_free_struct(data);
		free(color);
		free(data);
		free(map);
	}
}
