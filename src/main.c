/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 12:37:24 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 14:09:03 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit_sucess(t_data *data, t_map *map, t_color *color)
{
	ft_free_struct(data);
	free(data);
	ft_free_tab(map->map_2d);
	free(map);
	free(color);
	while (1)
		;
	exit(EXIT_SUCCESS);
}

void	ft_exit(t_data *data, t_map *map, t_color *color, int f)
{
	if (f == 1)
	{
		ft_free_struct(data);
		free(data);
	}
	if (f == 2)
	{
		ft_free_struct(data);
		free(data);
		ft_strdel(&map->map_1d);
		if (map->map_2d)
			ft_free_tab(map->map_2d);
		free(map);
	}
	if (f == 3)
	{
		ft_free_struct(data);
		free(data);
		ft_strdel(&map->map_1d);
		if (map->map_2d)
			ft_free_tab(map->map_2d);
		free(map);
		free(color);
	}
	while (1)
		;
	exit(EXIT_FAILURE);
}

void	print_params(t_data *data, t_map *map)
{
	ft_dprintf(2, "res_x:\t%d\nres_y:\t%d\n", data->res_x, data->res_y);
	ft_dprintf(2, "south_texture:\t|%s|\n", data->south_texture);
	ft_dprintf(2, "north_texture:\t|%s|\n", data->north_texture);
	ft_dprintf(2, "west_texture:\t|%s|\n", data->west_texture);
	ft_dprintf(2, "east_texture:\t|%s|\n", data->east_texture);
	ft_dprintf(2, "sprite_texture:\t|%s|\n", data->sprite_texture);
	ft_dprintf(2, "color_floor:\t%d\n", data->color_floor);
	ft_dprintf(2, "color_sky:\t%d\n", data->color_sky);
	ft_putstr_tab(map->map_2d);
	ft_dprintf(2, "pos_x:\t\t%d\n", map->start_pos_x);
	ft_dprintf(2, "compass:\t%c\n", map->compass);
	ft_dprintf(2, "pos_y:\t\t%d\n", map->start_pos_y);
}

int		main(int ac, char **av)
{
	int		fd;
	t_data	*data;
	t_map	*map;
	t_color	*color;

	color = NULL;
	if (!(fd = open(av[1], O_RDONLY)))
		return (msg_error("open"));
	if (!(data = init_data(fd)))
		return (msg_error("malloc"));
	map = init_map(data, color);
	color = init_color(data, map);
	if (parsing_name(av[1]) == -1)
		ft_exit(data, map, color, 1);
	if (parsing_core(data, map, color) == -1)
		ft_exit(data, map, color, 3);
	if (ac == 3 && !ft_strcmp(av[ac - 1], "mabitebug"))
		print_params(data, map);
	ft_exit_sucess(data, map, color);
}
