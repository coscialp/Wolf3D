/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_sprite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 13:08:23 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 18:17:07 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

static void		sprite_parser(t_cub3d *c, int i, int j, int *x)
{
	if (c->map.map_2d[i][j] == '2' || c->map.map_2d[i][j] == '3' ||
	c->map.map_2d[i][j] == '4')
	{
		c->sprite[(*x)].x = i + 0.5;
		c->sprite[(*x)].y = j + 0.5;
		c->sprite[(*x)].type = c->map.map_2d[i][j] - 44;
		*x += 1;
	}
}

static void		check_sprite(t_cub3d *c)
{
	int			i;
	int			j;

	i = 0;
	while (c->map.map_2d[i])
	{
		j = 0;
		while (c->map.map_2d[i][j])
		{
			if (c->map.map_2d[i][j] == '2' || c->map.map_2d[i][j] == '3'
			|| c->map.map_2d[i][j] == '4')
				c->data.num_sprite += 1;
			j++;
		}
		i++;
	}
}

int				parsing_sprite(t_cub3d *c)
{
	int			i;
	int			j;
	int			x;

	i = 0;
	x = 0;
	free(c->sprite);
	c->data.num_sprite = 0;
	check_sprite(c);
	i = 0;
	if (!(c->sprite = ft_memalloc(sizeof(t_sprite) * c->data.num_sprite)))
		ft_exit(c);
	while (c->map.map_2d[i])
	{
		j = 0;
		while (c->map.map_2d[i][j])
		{
			sprite_parser(c, i, j, &x);
			j++;
		}
		i++;
	}
	return (1);
}
