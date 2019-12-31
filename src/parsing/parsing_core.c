/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_core.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 14:17:51 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 15:34:56 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

int		parsing_analyser(char *line, t_cub3d *c)
{
	if (line[0] == 'F')
	{
		if (c->data.col_floor != -1 || !(parsing_color(line, c)))
			return (msg_error("color"));
	}
	else if (line[0] == 'C')
	{
		if (c->data.col_ceil != -1 || !(parsing_color(line, c)))
			return (msg_error("color"));
	}
	else if (line[0] == 'R' || line[0] == 'N' || line[0] == 'S' ||
	line[0] == 'W' || line[0] == 'E')
	{
		if (parsing_texture(line, 0, &c->data) <= 0)
			return (-1);
	}
	else if (ft_ismap(line[0]))
	{
		if (read_map(c->data.fd, &c->map, line) == -1)
			return (-1);
	}
	else if (line[0] != 0)
		return (msg_error("map"));
	return (1);
}

int		parsing_end(t_data *data, t_map *map)
{
	if (data->col_floor == -1 || data->col_ceil == -1)
		return (msg_error("color"));
	if (data->res_x == -1 || data->res_y == -1)
		return (msg_error("resolution"));
	if (!texture_is_valid(data->east_texture) ||
	!texture_is_valid(data->west_texture) ||
	!texture_is_valid(data->south_texture) ||
	!texture_is_valid(data->north_texture) ||
	!texture_is_valid(data->sprite_texture))
		return (msg_error("texture"));
	if (map->start_pos_x == -1 || map->start_pos_y == -1 || !map->compass)
		return (msg_error("player"));
	return (1);
}

void	parsing_core(t_cub3d *c)
{
	char	*current_line;
	size_t	i;

	if (secu_initialize(&c->map.map_1d, c->data.fd) == -1)
		ft_exit(c);
	while (get_next_line(c->data.fd, &current_line) > 0)
	{
		i = 0;
		while (current_line[i] && ft_isspace(current_line[i]))
			i++;
		if (parsing_analyser(current_line + i, c) == -1)
		{
			ft_strdel(&current_line);
			ft_exit(c);
		}
		ft_strdel(&current_line);
	}
	if ((parsing_map(c) == -1) || parsing_end(&c->data, &c->map) == -1)
		ft_exit(c);
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
