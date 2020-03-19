/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_sprite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 13:08:23 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/03/18 14:41:48 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

static void		sprite_parser(t_cub3d *c, int i, int j, int *x)
{
	if (map()->map_2d[i][j] == '2' || map()->map_2d[i][j] == '3' ||
	map()->map_2d[i][j] == '4' || map()->map_2d[i][j] == 'A')
	{
		c->sprite[(*x)].x = i + 0.5;
		c->sprite[(*x)].y = j + 0.5;
		c->sprite[(*x)].type = map()->map_2d[i][j] - 46;
		if (map()->map_2d[i][j] == 'A')
			c->sprite[(*x)].type = BULLET;
		c->sprite[(*x)].frame = 0;
		*x += 1;
	}
}

static int		check_sprite(void)
{
	int			i;
	int			j;
	int			ret;

	i = 0;
	ret = 0;
	while (map()->map_2d[i])
	{
		j = 0;
		while (map()->map_2d[i][j])
		{
			if (map()->map_2d[i][j] == '2' || map()->map_2d[i][j] == '3'
			|| map()->map_2d[i][j] == '4' || map()->map_2d[i][j] == 'A')
				ret += 1;
			j++;
		}
		i++;
	}
	return (ret);
}

int				parsing_sprite(t_cub3d *c)
{
	int			i;
	int			j;
	int			x;

	i = 0;
	x = 0;
	i = check_sprite();
	data()->num_sprite = i;
	i = 0;
	while (map()->map_2d[i])
	{
		j = 0;
		while (map()->map_2d[i][j])
		{
			sprite_parser(c, i, j, &x);
			j++;
		}
		i++;
	}
	return (1);
}
