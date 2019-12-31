/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   other_event.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 16:13:20 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/30 14:07:03 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

int		close_prgm(t_cub3d *c)
{
	mlx_destroy_window(c->data.ptrwin, c->data.win);
	ft_exit_sucess(c);
	return (1);
}
