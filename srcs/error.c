/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 12:38:37 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 18:35:36 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_isargb(unsigned char color)
{
	if (color < 0 || color > 255)
		return (0);
	return (1);
}

int		ft_ispos(char pos)
{
	if (pos == 'N' || pos == 'W' || pos == 'E' || pos == 'S')
		return (1);
	return (0);
}

int		ft_ismap(char c)
{
	if (c == '1' || c == '0' || c == '2')
		return (1);
	return (0);
}

int		secu_initialize(char **map_1d, int fd)
{
	char	buf[BUFFER_SIZE];

	if (read(fd, buf, 0) > 0)
		return (msg_error("read"));
	if (!(*map_1d = ft_strdup("")))
		return (msg_error("malloc"));
	return (1);
}

int		msg_error(char *reason)
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
	if (!ft_strcmp(reason, "color"))
		ft_dprintf(2, "Error\nNot valid color!\n");
	if (!ft_strcmp(reason, "map"))
		ft_dprintf(2, "Error\nNot valid map!\n");
	if (!ft_strcmp(reason, "wall"))
		ft_dprintf(2, "Error\nMap has borderless!\n");
	if (!ft_strcmp(reason, "player"))
		ft_dprintf(2, "Error\nPlayer can't be multiple position\n");
	return (-1);
}
