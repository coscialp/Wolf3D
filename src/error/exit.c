/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exit.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 18:32:44 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 20:15:45 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit(t_cub3d *c, int f)
{
	close(c->data->fd);
	if (f == 1)
		ft_free_struct(c->data);
	if (f == 2)
	{
		ft_free_struct(c->data);
		ft_strdel(&c->map->map_1d);
		if (c->map->map_2d)
			ft_free_tab(c->map->map_2d);
		free(c->map);
	}
	if (f == 3)
	{
		ft_free_struct(c->data);
		ft_strdel(&c->map->map_1d);
		if (c->map->map_2d)
			ft_free_tab(c->map->map_2d);
		free(c->map);
		free(c->color);
	}
	free(c);
	exit(EXIT_FAILURE);
}
