/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_map.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 19:00:10 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 18:55:30 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_cub3d *c, char pos, int i, int j)
{
	PLAYER.pos_x = i + 0.5f;
	PLAYER.pos_y = j + 0.5f;
	MAP->start_pos_x = i;
	MAP->start_pos_y = j;
	MAP->compass = pos;
	if (pos == 'N')
		PLAYER.rotation = 0;
	else if (pos == 'S')
		PLAYER.rotation = 180;
	else if (pos == 'E')
		PLAYER.rotation = 90;
	else if (pos == 'W')
		PLAYER.rotation = 270;
}

int		check_map(t_map *map, int i, int j, t_cub3d *c)
{
	if (i == map->height || i == 0 || j == map->length || j == 0)
		if (map->map_2d[i][j] != '1')
			return (msg_error("wall"));
	if (ft_ispos(map->map_2d[i][j]))
	{
		if (map->compass)
			return (msg_error("player"));
		init_player(c, map->map_2d[i][j], i, j);
	}
	else if (map->map_2d[i][j] != '0' && map->map_2d[i][j] != '1' &&
	map->map_2d[i][j] != '2')
		return (msg_error("map"));
	return (1);
}

int		parsing_map(t_cub3d *c)
{
	int		i;
	int		j;
	char	*map_without_space;

	i = 0;
	if (!(map_without_space = ft_strwcdup(MAP->map_1d, ' ')))
		return (msg_error("malloc"));
	ft_strdel(&MAP->map_1d);
	if (!(MAP->map_2d = ft_split_line(map_without_space)))
		return (msg_error("malloc"));
	ft_strdel(&map_without_space);
	if (map_dimension(MAP) == -1)
		return (-1);
	while (MAP->map_2d[i])
	{
		j = 0;
		while (MAP->map_2d[i][j])
		{
			if (check_map(MAP, i, j, c) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int		read_map(int fd, t_map *map, char *current_line)
{
	char	*line_map;

	if (!(map->map_1d = ft_strfjoin(map->map_1d, current_line, 1)))
		return (msg_error("malloc"));
	if (!(map->map_1d = ft_strfjoin(map->map_1d, "\n", 1)))
		return (msg_error("malloc"));
	while (get_next_line(fd, &line_map) > 0)
	{
		if (!(map->map_1d = ft_strfjoin(map->map_1d, line_map, 3)))
			return (msg_error("malloc"));
		if (!(map->map_1d = ft_strfjoin(map->map_1d, "\n", 1)))
			return (msg_error("malloc"));
	}
	return (1);
}

int		map_dimension(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!map->map_2d[i])
		return (msg_error("map"));
	while (map->map_2d[i][j])
		j++;
	while (map->map_2d[i])
		i++;
	map->length = j;
	map->height = i;
	i = 1;
	while (map->map_2d[i + 1])
		if (ft_strlen(map->map_2d[i++]) != (size_t)map->length)
			return (msg_error("map"));
	return (1);
}
