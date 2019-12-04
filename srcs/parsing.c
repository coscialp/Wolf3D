/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 16:31:43 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 19:20:30 by coscialp    ###    #+. /#+    ###.fr     */
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
	char	**c;

	if (!(c = ft_split(line + 1, ',')))
		return (-1);
	if (!ft_strisdigit(c[0]) || !(ft_atoi(c[0]) >= 0 && ft_atoi(c[0]) <= 255))
		return (0);
	color->rgba.r = ft_atoi(c[0]);
	if (!ft_strisdigit(c[1]) || !(ft_atoi(c[1]) >= 0 && ft_atoi(c[1]) <= 255))
		return (0);
	color->rgba.g = ft_atoi(c[1]);
	if (!ft_strisdigit(c[2]) || !(ft_atoi(c[2]) >= 0 && ft_atoi(c[2]) <= 255))
		return (0);
	color->rgba.b = ft_atoi(c[2]);
	data->color_sky = line[0] == 'C' ? color->color : data->color_sky;
	data->color_floor = line[0] == 'F' ? color->color : data->color_floor;
	if (c[3])
		return (0);
	ft_free_tab(c);
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
