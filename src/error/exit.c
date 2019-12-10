/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exit.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 18:32:44 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 18:44:03 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit(t_data *data, t_map *map, t_color *color, int f)
{
	close(data->fd);
	if (f == 1)
	{
		ft_free_struct(data);
	}
	if (f == 2)
	{
		ft_free_struct(data);
		ft_strdel(&map->map_1d);
		if (map->map_2d)
			ft_free_tab(map->map_2d);
		free(map);
	}
	if (f == 3)
	{
		ft_free_struct(data);
		ft_strdel(&map->map_1d);
		if (map->map_2d)
			ft_free_tab(map->map_2d);
		free(map);
		free(color);
	}
	exit(EXIT_FAILURE);
}
