/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exit.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 18:32:44 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 11:24:03 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit(t_cub3d *c)
{
	close(c->data.fd);
	ft_free_struct(c->data);
	ft_strdel(&c->map.map_1d);
	if (c->map.map_2d)
		ft_free_tab(c->map.map_2d);
	free(c);
	exit(EXIT_FAILURE);
}
