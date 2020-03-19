/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   icanmove.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 15:29:36 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/03/18 16:21:38 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

char	is_wall(char **map, int i, int j)
{
	if (map[i][j] == '1'|| map[i][j] == '5')
		return (1);
	return (0);
}

void	change_dist_sprite(t_cub3d *c)
{
	int i = 0;

	while (i < data()->num_sprite)
	{
		c->sprite[i].dist =  (player()->pos_x - c->sprite[i].x) *
		(player()->pos_x - c->sprite[i].x) +
		(player()->pos_y - c->sprite[i].y) * (player()->pos_y - c->sprite[i].y);
		i++;
	}
}

int no_object(t_cub3d *c)
{
	int i = 0;


	change_dist_sprite(c);
	while (i < data()->num_sprite)
	{
		if (c->sprite[i].dist < 0.15 && c->sprite[i].type != EMPTY && c->sprite[i].type != BULLET && c->sprite[i].type != ENNEMIES_DEAD)
			return (1);
		i++;
	}
	return (0);
}

void	icanmove_x(t_cub3d *c, char orientation)
{
	if (is_wall(map()->map_2d, (int)player()->pos_x, (int)player()->pos_y) && orientation == 'U')
		player()->pos_x -= player()->dir.x * c->movspeed;
	else if (is_wall(map()->map_2d, (int)player()->pos_x, (int)player()->pos_y) &&
	orientation == 'D')
		player()->pos_x += player()->dir.x * c->movspeed;
}

void	icanmove_y(t_cub3d *c, char orientation)
{
	if (is_wall(map()->map_2d, (int)player()->pos_x, (int)player()->pos_y) && orientation == 'U')
		player()->pos_y -= player()->dir.y * c->movspeed;
	else if (is_wall(map()->map_2d, (int)player()->pos_x, (int)player()->pos_y) && orientation == 'D')
		player()->pos_y += player()->dir.y * c->movspeed;
}

void	icanmove_x_lat(t_cub3d *c, char orientation)
{
	if (is_wall(map()->map_2d, (int)player()->pos_x, (int)player()->pos_y) && orientation == 'R')
		player()->pos_x -= data()->plane.x * c->movspeed;
	else if (is_wall(map()->map_2d, (int)player()->pos_x, (int)player()->pos_y) && orientation == 'L')
		player()->pos_x += data()->plane.x * c->movspeed;
}

void	icanmove_y_lat(t_cub3d *c, char orientation)
{
	if (is_wall(map()->map_2d, (int)player()->pos_x, (int)player()->pos_y) && orientation == 'R')
		player()->pos_y -= data()->plane.y * c->movspeed;
	else if (is_wall(map()->map_2d, (int)player()->pos_x, (int)player()->pos_y) && orientation == 'L')
		player()->pos_y += data()->plane.y * c->movspeed;
}
