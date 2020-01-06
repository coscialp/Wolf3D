/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_sprite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 13:08:23 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 17:54:59 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

int		parsing_sprite(t_cub3d *c)
{
	int			i;
	int			j;
	static int	pos = 0;

	i = 0;
	if (!(c->sprite = malloc(sizeof(t_sprite) * c->data.num_sprite)))
		ft_exit(c);
	while (c->map.map_2d[i])
	{
		j = 0;
		while (c->map.map_2d[i][j])
		{
			if (c->map.map_2d[i][j] == '2')
			{
				c->sprite[pos].x = j + 0.5;
				c->sprite[pos].y = i + 0.5;
				pos++;
			}
			j++;
		}
		i++;
	}
	return (1);
}
