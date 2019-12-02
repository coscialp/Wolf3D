/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handler_struct.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 12:30:07 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 14:23:14 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

t_data		*init_data(void)
{
	t_data	*data;

	if (!(data = malloc(sizeof(t_data) * 1)))
		return (NULL);
	data->res_x = 0;
	data->res_y = 0;
	data->color_floor = 0;
	data->color_sky = 0;
	data->north_texture = NULL;
	data->south_texture = NULL;
	data->west_texture = NULL;
	data->east_texture = NULL;
	data->sprite_texture = NULL;
	return (data);
}

t_map		*init_map(void)
{
	t_map	*map;

	if (!(map = malloc(sizeof(t_map) * 1)))
		return (NULL);
	map->start_pos_x = -1;
	map->start_pos_y = -1;
	return (map);
}

t_color		*init_color(void)
{
	t_color		*color;

	if (!(color = (t_color*)malloc(sizeof(t_color) * 1)))
		return (NULL);
	color->color = 0;
	color->rgba.a = 0;
	color->rgba.b = 0;
	color->rgba.r = 0;
	color->rgba.g = 0;
	return (color);
}

void		ft_free_struct(t_data *data)
{
	ft_strdel(&data->sprite_texture);
	ft_strdel(&data->north_texture);
	ft_strdel(&data->south_texture);
	ft_strdel(&data->west_texture);
	ft_strdel(&data->east_texture);
}
