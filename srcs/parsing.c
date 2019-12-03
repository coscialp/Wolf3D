/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 16:31:43 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 19:39:34 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

int		parsing_resolution(char *line, t_data *data)
{
	int		i;

	i = 0;
	data->res_x = ft_atoi(line);
	while (line[i] && ft_isspace(line[i]))
		i++;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	data->res_y = ft_atoi(line + i);
	while (line[i] && ft_isspace(line[i]))
		i++;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i])
		return (msg_error("resolution"));
	if (data->res_x <= 0 || data->res_y <= 0)
		return (msg_error("resolution"));
	return (1);
}

int		parsing_color(char *line, t_color *color, t_data *data)
{
	char	**col;

	if (!(col = ft_split(line + 1, ',')))
		return (-1);
	if (ft_strisdigit(col[0]) && ft_atoi(col[0]) >= 0 && ft_atoi(col[0]) <= 255)
		color->rgba.r = ft_atoi(col[0]);
	else
		return (0);
	if (ft_strisdigit(col[1]) && ft_atoi(col[1]) >= 0 && ft_atoi(col[1]) <= 255)
		color->rgba.g = ft_atoi(col[1]);
	else
		return (0);
	if (ft_strisdigit(col[2]) && ft_atoi(col[2]) >= 0 && ft_atoi(col[2]) <= 255)
		color->rgba.b = ft_atoi(col[2]);
	else
		return (0);
	ft_free_tab(col);
	if (line[0] == 'C')
		data->color_sky = color->color;
	if (line[0] == 'F')
		data->color_floor = color->color;
	if (col[3])
		return (0);
	//ft_dprintf(1, "r:\t%d\ng:\t%d\nb:\t%d\n", color->rgba.r, color->rgba.g, color->rgba.b);
	return (1);
}

int		parsing_texture(char *line, size_t i, t_data *data)
{
	if (line[i] == 'R')
		return (parsing_resolution(line + i + 1, data));
	else if (line[i] == 'S' && line[i + 1] == 'O')
		return (((data->south_texture = ft_strdup(line + i + 3)) != NULL));
	else if (line[i] == 'N' && line[i + 1] == 'O')
		return (((data->north_texture = ft_strdup(line + i + 3)) != NULL));
	else if (line[i] == 'W' && line[i + 1] == 'E')
		return (((data->west_texture = ft_strdup(line + i + 3)) != NULL));
	else if (line[i] == 'E' && line[i + 1] == 'A')
		return (((data->east_texture = ft_strdup(line + i + 3)) != NULL));
	else if (line[i] == 'S')
		return (((data->sprite_texture = ft_strdup(line + i + 2)) != NULL));
	return (1);
}

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
	if ((parsing_map(map) == -1))
		return (-1);
	return (1);
}
