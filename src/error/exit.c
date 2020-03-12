/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:32:44 by coscialp          #+#    #+#             */
/*   Updated: 2020/03/12 19:05:44 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	ft_exit(t_cub3d *c)
{
	close(data()->fd);
	ft_strdel(&map()->map_1d);
	ft_free_struct();
	if (map()->map_2d)
		ft_free_tab(map()->map_2d);
	free(c);
	exit(EXIT_FAILURE);
}
