/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 12:37:24 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 15:18:09 by coscialp    ###    #+. /#+    ###.fr     */
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
		if (map->map_2d)
			ft_free_tab(map->map_2d);
		free(map);
	}
	if (f == 3)
	{
		ft_free_struct(data);
		free(data);
		if (map->map_2d)
			ft_free_tab(map->map_2d);
		free(map);
		free(color);
	}
	exit(EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	int		fd;
	t_data	*data;
	t_map	*map;
	t_color	*color;

	if (ac == 2)
	{
		if (parsing_name(av[ac - 1]) == -1)
			return (EXIT_FAILURE);
		if (!(fd = open(av[ac - 1], O_RDONLY)))
			return (msg_error("open"));
		if (!(data = init_data(fd)))
			return (msg_error("malloc"));
		if (!(map = init_map()))
		{
			msg_error("malloc");
			ft_exit(data, map, color, 1);
		}
		color = init_color(data, map);
		if (parsing_core(data, map, color) == -1)
			ft_exit(data, map, color, 3);
	}
	ft_exit_sucess(data, map, color);
}
