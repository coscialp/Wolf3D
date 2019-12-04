/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_core.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 14:17:51 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 17:34:05 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

int		parsing_analyser(char *line, t_data *data, t_map *map, t_color *color)
{
	if (line[0] == 'C' || line[0] == 'F')
	{
		if (!(parsing_color(line, color, data)))
			return (msg_error("color"));
	}
	else if (line[0] == 'R' || line[0] == 'N' || line[0] == 'S' ||
	line[0] == 'W' || line[0] == 'E')
	{
		if (parsing_texture(line, 0, data) <= 0)
			return (-1);
	}
	else if (ft_ismap(line[0]))
	{
		if (read_map(data->fd, map, line) == -1)
			return (-1);
	}
	else if (line[0] != 0)
		return (msg_error("map"));
	return (1);
}

int		parsing_end(t_data *data, t_map *map)
{
	if (data->color_floor == -1 || data->color_sky == -1)
		return (msg_error("color"));
	if (data->res_x == -1 || data->res_y == -1)
		return (msg_error("resolution"));
	if (!data->east_texture || !data->west_texture || !data->south_texture ||
	!data->north_texture || !data->sprite_texture)
		return (msg_error("texture"));
	if (map->start_pos_x == -1 || map->start_pos_y == -1 || !map->compass)
		return (msg_error("player"));
	return (1);
}

int		parsing_core(t_data *data, t_map *map, t_color *color)
{
	char	*current_line;
	size_t	i;

	if (secu_initialize(&map->map_1d, data->fd) == -1)
		return (-1);
	while (get_next_line(data->fd, &current_line) > 0)
	{
		i = 0;
		while (current_line[i] && ft_isspace(current_line[i]))
			i++;
		if (parsing_analyser(current_line + i, data, map, color) == -1)
			return (-1);
		ft_strdel(&current_line);
	}
	if ((parsing_map(map) == -1) || parsing_end(data, map) == -1)
		return (-1);
	return (1);
}

int		parsing_name(char *name)
{
	char	**extented;
	size_t	i;

	i = 0;
	if (!(extented = ft_split(name, '.')))
		return (msg_error("malloc"));
	while (extented[i + 1])
		i++;
	if (ft_strcmp(extented[i], "cub"))
		return (msg_error("file"));
	ft_free_tab(extented);
	return (1);
}
