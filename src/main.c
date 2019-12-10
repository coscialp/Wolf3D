/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 12:37:24 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 18:52:08 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit_sucess(t_data *data, t_map *map, t_color *color)
{
	close(data->fd);
	ft_free_struct(data);
	ft_free_tab(map->map_2d);
	free(map);
	free(color);
	exit(EXIT_SUCCESS);
}

int		main(int ac, char **av)
{
	t_data	*data;
	t_map	*map;
	t_color	*color;

	color = NULL;
	if (ac >= 2 && ac <= 3)
	{
		data = init_data(av[1]);
		map = init_map(data, color);
		color = init_color(data, map);
		if (parsing_name(av[1]) == -1)
			ft_exit(data, map, color, 1);
		parsing_core(data, map, color);
		if (ac == 3 && !ft_strcmp(av[ac - 1], "mabitebug"))
			print_params(data, map);
		if (!(data->win = mlx_new_window(data->ptrwin,
		data->res_x, data->res_y, "Cub3D")))
			ft_exit(data, map, color, 3);
		mlx_loop(data->ptrwin);
		ft_exit_sucess(data, map, color);
	}
	return (msg_error("argument"));
}
