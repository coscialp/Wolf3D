/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:38:37 by coscialp          #+#    #+#             */
/*   Updated: 2020/03/12 18:30:31 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

t_bool	ft_isargb(unsigned char color)
{
	if (color < 0 || color > 255)
		return (FALSE);
	return (TRUE);
}

t_bool	ft_ispos(char pos)
{
	if (pos == 'N' || pos == 'W' || pos == 'E' || pos == 'S')
		return (TRUE);
	return (FALSE);
}

t_bool	ft_ismap(char c)
{
	if (c == '1' || c == '0' || c == '2')
		return (TRUE);
	return (FALSE);
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
	else if (!ft_strcmp(reason, "argument"))
		ft_dprintf(2, "Error\nNumber of arguments are not valid!\n");
	else if (!ft_strcmp(reason, "read"))
		ft_dprintf(2, "Error\nMap cannot be read!\n");
	else if (!ft_strcmp(reason, "texture"))
		ft_dprintf(2, "Error\nMissing texture\n");
	else if (!ft_strcmp(reason, "malloc"))
		ft_dprintf(2, "Error\nMemory allocation failed!\n");
	else if (!ft_strcmp(reason, "resolution"))
		ft_dprintf(2, "Error\nScreen's resolution is not valid!\n");
	else if (!ft_strcmp(reason, "file"))
		ft_dprintf(2, "Error\nNot valid file!\n");
	else if (!ft_strcmp(reason, "color"))
		ft_dprintf(2, "Error\nNot valid color!\n");
	else if (!ft_strcmp(reason, "map"))
		ft_dprintf(2, "Error\nNot valid map!\n");
	else if (!ft_strcmp(reason, "wall"))
		ft_dprintf(2, "Error\nMap is borderless!\n");
	else if (!ft_strcmp(reason, "player"))
		ft_dprintf(2, "Error\nPlayer can't be multiple position\n");
	return (-1);
}
