/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 12:38:37 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 14:55:13 by coscialp    ###    #+. /#+    ###.fr     */
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
	return (-1);
}
