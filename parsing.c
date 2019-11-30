/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 16:31:43 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 20:04:45 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_error(char *reason)
{
	if (!ft_strcmp(reason, "open"))	
		ft_dprintf(2, "Error\nMap cannot be open!\n");
	if (!ft_strcmp(reason, "read"))	
		ft_dprintf(2, "Error\nMap cannot be read!\n");
	if (!ft_strcmp(reason, "malloc"))	
		ft_dprintf(2, "Error\nMemory allocation failed!\n");
	if (!ft_strcmp(reason, "resolution"))	
		ft_dprintf(2, "Error\nScreen's resolution are not valid!\n");
	if (!ft_strcmp(reason, "file"))	
		ft_dprintf(2, "Error\nNot valid file!\n");
	return (-1);
}

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
	if (data->res_x <= 0 || data->res_y <= 0)
		return (ft_error("resolution"));
	return (1);
}

int		parsing_texture(char *current_line, size_t i, t_data *data)
{
	if (current_line[i] == 'R')
		return (parsing_resolution(current_line + i + 1, data));
	else if (current_line[i] == 'S' && current_line[i + 1] == 'O')
		return (((data->south_texture = ft_strdup(current_line + i + 3)) != NULL));
	else if (current_line[i] == 'N' && current_line[i + 1] == 'O')
		return (((data->north_texture = ft_strdup(current_line + i + 3)) != NULL));
	else if (current_line[i] == 'W' && current_line[i + 1] == 'E')
		return (((data->west_texture = ft_strdup(current_line + i + 3)) != NULL));
	else if (current_line[i] == 'E' && current_line[i + 1] == 'A')
		return (((data->east_texture = ft_strdup(current_line + i + 3)) != NULL));
	else if (current_line[i] == 'S')
		return (((data->sprite_texture = ft_strdup(current_line + i + 2)) != NULL));
	return (1);
}

int		parsing_core(int fd, t_data *data, t_map *map)
{
	char	*current_line;
	size_t	i;

	if (read(fd, current_line, 0) > 0)
		return (ft_error("read"));
	while (get_next_line(fd, &current_line) > 0)
	{
		i = 0;
		while (current_line[i] && ft_isspace(current_line[i]))
			i++;
		if (parsing_texture(current_line, i, data) <= 0)
			return (-1);
		ft_strdel(&current_line);
	}
	ft_strdel(&current_line);
	return (1);
}

t_data	*init_data(void)
{
	t_data	*data;
	
	if (!(data = malloc(sizeof(t_data) * 1)))
		return (NULL);
	data->res_x = 0;
	data->res_y= 0;
	data->color_floor = 0;
	data->color_sky = 0;
	data->north_texture = NULL;
	data->south_texture = NULL;
	data->west_texture = NULL;
	data->east_texture = NULL;
	data->sprite_texture = NULL;
	return (data);
}

t_map	*init_map(void)
{
	t_map	*map;

	if (!(map = malloc(sizeof(t_map) * 1)))
		return (NULL);
	map->start_pos_x = -1;
	map->start_pos_y = -1;
	return (map);
}

void	ft_free_struct(t_data *data, t_map *map)
{
	ft_strdel(&data->sprite_texture);
	ft_strdel(&data->north_texture);
	ft_strdel(&data->south_texture);
	ft_strdel(&data->west_texture);
	ft_strdel(&data->east_texture);
}

int main(int ac, char **av)
{
	int	fd;
	t_data	*data;
	t_map	*map;

	if (ac == 2)
	{
		if (!(data = init_data()))
			return (ft_error("malloc"));
		if (!(map = init_map()))
			return (ft_error("malloc"));
		if (!(fd = open(av[ac - 1], O_RDONLY)))
			return (ft_error("open"));
		if (parsing_core(fd, data, map) == -1)
			return (-1);
		ft_dprintf(1, "res_x:\t%d\nres_y:\t%d\n", data->res_x, data->res_y);
		ft_dprintf(1, "south_texture:\t|%s|\nnorth_texture:\t|%s|\nwest_texture:\t|%s|\neast_texture:\t|%s|\nsprite_texture:\t|%s|\n", data->south_texture, data->north_texture, data->west_texture, data->east_texture, data->sprite_texture);
		ft_free_struct(data, map);
		free(data);
		free(map);
	}
}