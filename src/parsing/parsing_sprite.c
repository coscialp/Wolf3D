/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_sprite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 13:08:23 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 12:55:34 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

static void	sprite_parser(t_cub3d *c, int i, int j, t_pos *pos)
{
	if (c->map.map_2d[i][j] == '2')
	{
		c->sprite[pos->x].x = i + 0.5;
		c->sprite[pos->x].y = j + 0.5;
		pos->x += 1;
	}
	else if (c->map.map_2d[i][j] == '3' || c->map.map_2d[i][j] == '4')
	{
		c->sprite2[pos->y].x = i + 0.5;
		c->sprite2[pos->y].y = j + 0.5;
		pos->y += 1;
	}
}

int			parsing_sprite(t_cub3d *c)
{
	int			i;
	int			j;
	t_pos		pos;

	i = 0;
	pos.x = 0;
	pos.y = 0;
	free(c->sprite);
	free(c->sprite2);
	if (!(c->sprite = ft_memalloc(sizeof(t_sprite) * c->data.num_sprite)))
		ft_exit(c);
	if (!(c->sprite2 = ft_memalloc(sizeof(t_sprite) * c->data.num_sprite2)))
		ft_exit(c);
	while (c->map.map_2d[i])
	{
		j = 0;
		while (c->map.map_2d[i][j])
		{
			sprite_parser(c, i, j, &pos);
			j++;
		}
		i++;
	}
	return (1);
}
