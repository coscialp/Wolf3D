/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 16:31:43 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 16:31:39 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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

int		parsing_resolution(char *line, t_data *data)
{
	int		i;

	i = 0;
	data->res_x = ft_atoi(line);
	ft_whilestris(line, &i, ft_isspace, 0);
	ft_whilestris(line, &i, ft_isdigit, 0);
	data->res_y = ft_atoi(line + i);
	ft_whilestris(line, &i, ft_isspace, 0);
	ft_whilestris(line, &i, ft_isdigit, 0);
	ft_whilestris(line, &i, ft_isspace, 0);
	if (line[i])
		return (msg_error("resolution"));
	if (data->res_x <= 0 || data->res_y <= 0)
		return (msg_error("resolution"));
	return (1);
}

int		parsing_color(char *line, t_color *color, t_data *data)
{
	char	**c;
	int		i;
	int		j;

	j = 0;
	if (!(c = ft_split(line + 1, ',')))
		return (-1);
	while (c[j])
	{
		i = 0;
		ft_whilestris(c[j], &i, ft_isspace, 0);
		ft_whilestris(c[j], &i, ft_isdigit, 0);
		ft_whilestris(c[j], &i, ft_isspace, 0);
		if (!ft_strisdigit(c[j]) || !(ft_atoi(c[j]) >= 0 &&
		ft_atoi(c[j]) <= 255) || c[j][i] || j >= 3)
			return (0);
		j++;
	}
	color->rgba.r = ft_atoi(c[0]);
	color->rgba.g = ft_atoi(c[1]);
	color->rgba.b = ft_atoi(c[2]);
	data->color_sky = line[0] == 'C' ? color->color : data->color_sky;
	data->color_floor = line[0] == 'F' ? color->color : data->color_floor;
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

int		texture_is_valid(char *path)
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