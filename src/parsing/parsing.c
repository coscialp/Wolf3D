/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:31:43 by coscialp          #+#    #+#             */
/*   Updated: 2020/03/12 18:39:46 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

static int		ft_strisdigit(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_isspace(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int				parsing_resolution(char *line, t_data *data)
{
	int		i;

	i = 0;
	if (data->res_x != -1 || data->res_y != -1)
		return (msg_error("resolution"));
	data->res_x = ft_atoi(line);
	ft_whilestris(line, &i, ft_isspace, 0);
	ft_whilestris(line, &i, ft_isdigit, 0);
	data->res_y = ft_atoi(line + i);
	ft_whilestris(line, &i, ft_isspace, 0);
	ft_whilestris(line, &i, ft_isdigit, 0);
	ft_whilestris(line, &i, ft_isspace, 0);
	if (line[i])
		return (msg_error("resolution"));
	if (data->res_x < 50 || data->res_y < 50)
		return (msg_error("resolution"));
	if (data->res_y > 1440)
		data->res_y = 1440;
	if (data->res_x > 2560)
		data->res_x = 2560;
	return (1);
}

int				parsing_color(char *line)
{
	char	**col;
	int		i;
	int		j;
	t_color	color;

	j = 0;
	if (!(col = ft_split(line + 1, ',')))
		return (-1);
	while (col[j])
	{
		i = 0;
		ft_whilestris(col[j], &i, ft_isspace, 0);
		ft_whilestris(col[j], &i, ft_isdigit, 0);
		ft_whilestris(col[j], &i, ft_isspace, 0);
		if (!ft_strisdigit(col[j]) || !(ft_atoi(col[j]) >= 0 &&
		ft_atoi(col[j]) <= 255) || col[j][i] || j >= 3)
			return (ft_free_tab(col));
		j++;
	}
	color.rgba.r = ft_atoi(col[0]);
	color.rgba.g = ft_atoi(col[1]);
	color.rgba.b = ft_atoi(col[2]);
	data()->col_ceil = line[0] == 'C' ? color.color : data()->col_ceil;
	data()->col_floor = line[0] == 'F' ? color.color : data()->col_floor;
	ft_free_tab(col);
	return (1);
}

int				parsing_texture(char *line, size_t i, t_data *data)
{
	if (line[i] == 'R')
		return (parsing_resolution(line + i + 1, data));
	else if (line[i] == 'S' && line[i + 1] == 'O' && !data->south_texture)
		return (((data->south_texture = ft_strdup(line + i + 3)) != NULL));
	else if (line[i] == 'N' && line[i + 1] == 'O' && !data->north_texture)
		return (((data->north_texture = ft_strdup(line + i + 3)) != NULL));
	else if (line[i] == 'W' && line[i + 1] == 'E' && !data->west_texture)
		return (((data->west_texture = ft_strdup(line + i + 3)) != NULL));
	else if (line[i] == 'E' && line[i + 1] == 'A' && !data->east_texture)
		return (((data->east_texture = ft_strdup(line + i + 3)) != NULL));
	else if (line[i] == 'S' && !data->sprite_texture)
		return (((data->sprite_texture = ft_strdup(line + i + 2)) != NULL));
	return (msg_error("texture"));
}

int				texture_is_valid(char *path)
{
	int		fd;
	char	buf[BUFFER_SIZE];

	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);
	if (read(fd, buf, 0) != 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
