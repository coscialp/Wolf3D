/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 12:37:24 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/03/18 16:21:44 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	init_windows(t_cub3d *c)
{
	if (!(data()->ptrwin = mlx_init()))
		ft_exit(c);
	if (!(data()->win = mlx_new_window(data()->ptrwin,
	data()->res_x, data()->res_y, "Cub3D")))
		ft_exit(c);
	c->img.img = mlx_new_image(data()->ptrwin,
	data()->res_x, data()->res_y);
	c->img.ptr = (int *)mlx_get_data_addr(c->img.img, &c->img.bpp,
	&c->img.size_line, &c->img.endian);
	loading_all_tex(c);
	if (!(c->zbuffer = malloc(sizeof(double) * data()->res_x)))
		ft_exit(c);
}

void	ft_exit_sucess(t_cub3d *c)
{
	close(data()->fd);
	free(c->zbuffer);
	ft_free_struct();
	ft_free_tab(map()->map_2d);
	free(c);
	exit(EXIT_SUCCESS);
}

void	init_plane(t_cub3d *c)
{
	if (map()->compass == 'W')
	{
		data()->plane.x = -0.66;
		data()->plane.y = 0;
	}
	else if (map()->compass == 'E')
	{
		data()->plane.x = 0.66;
		data()->plane.y = 0;
	}
	else if (map()->compass == 'N')
	{
		data()->plane.x = 0;
		data()->plane.y = 0.66;
	}
	else if (map()->compass == 'S')
	{
		data()->plane.x = 0;
		data()->plane.y = -0.66;
	}
	c->movspeed = 0.075;
	c->rotspeed = 0.04;
	c->shoot = 0;
	c->action = 0;
	init_windows(c);
}

int		touching_ennemies(t_cub3d *c, t_vector shoot)
{
	int	i = 0;
	double	dist;

	while (i < c->size_near)
	{
		dist = (shoot.x - c->near[i].x) *
		(shoot.x - c->near[i].x) +
		(shoot.y - c->near[i].y) * (shoot.y - c->near[i].y);
		if (dist < 0.1 && (c->near[i].type == ENNEMIES_WAIT || (c->near[i].type >= ENNEMIES_RUN && c->near[i].type <= ENNEMIES_SHOOT)))
		{
			c->sprite[data()->num_sprite - 1 - i].type = ENNEMIES_BLESSED;
			c->sprite[data()->num_sprite - 1 - i].frame = 0;
			return (1);
		}
		i++;
	}
	return (0);
}

void	you_shoot(t_cub3d *c)
{
	t_vector	shoot;
	int			i;

	i = 0;
	shoot.x = player()->pos_x;
	shoot.y = player()->pos_y;
	while (!is_wall(map()->map_2d, (int)shoot.x, (int)shoot.y) && i <= player()->scope)
	{
		shoot.x += player()->dir.x * 0.5;
		if (is_wall(map()->map_2d, (int)shoot.x, (int)shoot.y))
			break ;
		shoot.y += player()->dir.y * 0.5;
		if (touching_ennemies(c, shoot))
			break ;
		i++;
	}
}

void	shoot(t_cub3d *c)
{
	static int	frame = 0;

	if (!c->shoot)
		draw_arms(c, player()->weapons);
	if (c->shoot == 1)
	{
		player()->shoot = 1;
		draw_arms(c, player()->weapons + 1);
		frame++;
		if (frame == 8)
		{
			c->shoot = 2;
			frame = 0;
		}
	}
	else if (c->shoot == 2)
	{
		draw_arms(c, player()->weapons + 2);
		frame++;
		if (frame == 2)
		{
			if (player()->weapons != KNIFE)
				player()->bullet--;
			you_shoot(c);
		}
		if (frame == 4)
		{
			c->shoot = 3;
			frame = 0;
		}
	}
	else if (c->shoot == 3)
	{
		draw_arms(c, player()->weapons);
		frame++;
		if (frame == 6)
		{
			c->shoot = 0;
			frame = 0;
			player()->shoot = 0;
		}
	}
}

void	take_object(t_cub3d *c)
{
	int	i = 0;

	while (i < c->size_near)
	{
		if (c->near[i].dist <= 0.25 && c->near[i].type == HEALTH && player()->life != 100)
		{	
			c->sprite[data()->num_sprite - 1 - i].type = EMPTY;
			player()->life += 10;
		}
		else if (c->near[i].dist <= 0.15 && c->near[i].type == BULLET)
		{	
			c->sprite[data()->num_sprite - 1 - i].type = EMPTY;
			player()->bullet += 4;
		}
		i++;
	}
}

void	IA_collision_x(t_sprite *sprite)
{
	if (map()->map_2d[(int)sprite->x][(int)sprite->y] == '1' ||
	map()->map_2d[(int)sprite->x][(int)sprite->y] == '5')
		sprite->x -= -player()->dir.x * 0.2;
}

void	IA_collision_y(t_sprite *sprite)
{
	if (map()->map_2d[(int)sprite->x][(int)sprite->y] == '1' ||
	map()->map_2d[(int)sprite->x][(int)sprite->y] == '5')
		sprite->y -= -player()->dir.y * 0.2;
}

void	IA_shoot(t_sprite ennemy)
{
	t_vector	shoot;
	double		dist;

	shoot.x = ennemy.x;
	shoot.y = ennemy.y;
	while (map()->map_2d[(int)shoot.x][(int)shoot.y] != '1' &&
	map()->map_2d[(int)shoot.x][(int)shoot.y] != '5')
	{
		shoot.x += -player()->dir.x * 0.5;
		if (map()->map_2d[(int)shoot.x][(int)shoot.y] == '1' ||
		map()->map_2d[(int)shoot.x][(int)shoot.y] == '5')
			break ;
		shoot.y += -player()->dir.y * 0.5;
		dist = (player()->pos_x - shoot.x) *
		(player()->pos_x - shoot.x) +
		(player()->pos_y - shoot.y) * (player()->pos_y - shoot.y);
		if (dist <= 0.5)
		{
			player()->life -= 5;
			break ;
		}
	}
}

void	IA_ennemies(t_cub3d *c)
{
	int	i = 0;

	while (i < c->size_near)
	{
		if (c->near[i].type == ENNEMIES_WAIT)
		{
			c->sprite[data()->num_sprite - i - 1].frame = 0;
			if (c->near[i].dist <= 30)
				c->sprite[data()->num_sprite - i - 1].type = ENNEMIES_RUN;
		}
		else if (c->near[i].type >= ENNEMIES_RUN && c->near[i].type <= ENNEMIES_RUN4)
		{
			if (c->near[i].dist <= 30 && c->near[i].dist >= 10 && c->near[i].frame == 3)
			{
				c->sprite[data()->num_sprite - i - 1].x += -player()->dir.x * 0.2;
				IA_collision_x(&c->sprite[data()->num_sprite - i - 1]);
				c->sprite[data()->num_sprite - i - 1].y += -player()->dir.y * 0.2;
				IA_collision_y(&c->sprite[data()->num_sprite - i - 1]);
				if ( c->near[i].type != ENNEMIES_RUN4)
					c->sprite[data()->num_sprite - i - 1].type += 1;
				else
					c->sprite[data()->num_sprite - i - 1].type = ENNEMIES_RUN;
				c->sprite[data()->num_sprite - i - 1].frame = 0;
			}
			else if (c->near[i].dist > 30)
				c->sprite[data()->num_sprite - i - 1].type = ENNEMIES_WAIT;
			else if (c->near[i].dist <= 10)
			{
				c->sprite[data()->num_sprite - i - 1].type = ENNEMIES_START;
				c->sprite[data()->num_sprite - i - 1].frame = 0;
			}
			else
				c->sprite[data()->num_sprite - i - 1].frame += 1;
		}
		else if (c->near[i].type == ENNEMIES_START)
		{
			if (c->near[i].dist > 30)
				c->sprite[data()->num_sprite - i - 1].type = ENNEMIES_WAIT;
			else if (c->near[i].frame == 30)
			{
				c->sprite[data()->num_sprite - i - 1].type = ENNEMIES_SHOOT;
				c->sprite[data()->num_sprite - i - 1].frame = 0;
			}
			else
				c->sprite[data()->num_sprite - i - 1].frame += 1;
		}
		else if (c->near[i].type == ENNEMIES_SHOOT)
		{
			if (c->near[i].dist > 30)
				c->sprite[data()->num_sprite - i - 1].type = ENNEMIES_WAIT;
			else if (c->near[i].frame == 6)
			{
				c->sprite[data()->num_sprite - i - 1].type = ENNEMIES_START;
				c->sprite[data()->num_sprite - i - 1].frame = 0;
			}
			else
				c->sprite[data()->num_sprite - i - 1].frame += 1;
			if (c->near[i].frame == 1)
				IA_shoot(c->near[i]);
		}
		else if (c->near[i].type >= ENNEMIES_BLESSED && c->near[i].type <= ENNEMIES_BLESSED3)
		{
			if (c->near[i].frame == 6)
			{
				if (c->near[i].type != ENNEMIES_BLESSED3)
					c->sprite[data()->num_sprite - i - 1].type += 1;
				else
				{
					c->sprite[data()->num_sprite - i - 1].type = ENNEMIES_DEAD;
					c->sprite[data()->num_sprite].type = BULLET;
					c->sprite[data()->num_sprite].x = c->sprite[data()->num_sprite - i - 1].x + -player()->dir.x * 0.25;
					c->sprite[data()->num_sprite].y = c->sprite[data()->num_sprite - i - 1].y + -player()->dir.y * 0.25;
					data()->num_sprite += 1;
				}
				c->sprite[data()->num_sprite - i - 1].frame = 0;
			}
			else
				c->sprite[data()->num_sprite - i - 1].frame += 1;
		}
		i++;
	}
}

void	action(t_cub3d *c)
{
	t_vector pos;
	static char	open = 0;

	pos.x = player()->pos_x + player()->dir.x;
	pos.y = player()->pos_y + player()->dir.y;
	if (map()->map_2d[(int)pos.x][(int)pos.y] == '5')
	{
		map()->map_2d[(int)pos.x][(int)pos.y]++;
		open = 1;
	}
	else if (map()->map_2d[(int)pos.x][(int)pos.y] == '6' + 8)
	{
		map()->map_2d[(int)pos.x][(int)pos.y]--;
		open = 2;
	}
	else if (open == 1)
	{
		map()->map_2d[(int)pos.x][(int)pos.y]++;
		if (map()->map_2d[(int)pos.x][(int)pos.y] == '6' + 8)
			open = 0;
	}
	else if (open == 2)
	{
		map()->map_2d[(int)pos.x][(int)pos.y]--;
		if (map()->map_2d[(int)pos.x][(int)pos.y] == '5')
			open = 0;
	}
	if (open == 0)
		c->action = 0;
}

void	print_bullet(void)
{
	char 	str[255];
	char	*nbr;

	ft_strcpy(str, "Bullets:\t");
	nbr = ft_itoa(player()->bullet);
	ft_strcat(str, nbr);
	ft_strdel(&nbr);
	mlx_string_put(data()->ptrwin, data()->win, data()->res_x / 32, data()->res_y / 32, 0xffffff, str);
}

int		main_loop(t_cub3d *c)
{
	if (c->move && !c->action)
		move_camera(c, c->move);
	if (c->rotate && !c->action)
		rotate(c, c->rotate);
	if (c->move_lat && !c->action)
		move_lat_camera(c, c->move_lat);
	if (c->action)
		action(c);
	raycast(c);
	second_raycast(c);
	take_object(c);
	if (player()->life > 100)
		player()->life = 100;
	if (player()->life <= 0)
	{
		ft_dprintf(1, "You are DEAD !\n");
		close_prgm(c);
	}
	if (c->movspeed == 0.15)
	{
		player()->stamina -= 1;
		if (player()->stamina < 0)
		{
			c->movspeed = 0.075;
			player()->stamina = 0;
		}
	}
	else
	{
		player()->stamina += 0.1;
		if (player()->stamina > 100)
			player()->stamina = 100;
	}
	if (player()->bullet <= 0)
	{
		player()->weapons = KNIFE;
		player()->scope = 1;
		player()->bullet = 0;
	}
	shoot(c);
	IA_ennemies(c);
	draw_lifebar(c);
	draw_staminabar(c);
	mlx_put_image_to_window(data()->ptrwin, data()->win, c->img.img, 0, 0);
	print_bullet();
	return (0);
}

t_data	*data(void)
{
	static t_data	data = {0};

	return (&data);
}

t_map	*map(void)
{
	static t_map	map = {0};

	return (&map);
}

t_player	*player(void)
{
	static t_player	player = {{0}, 0, 100, 0, 0, 0, GUN, 20, 8};

	return (&player);
}

int		main(int ac, char **av)
{
	t_cub3d	*c;

	if (ac >= 2 && ac <= 3)
	{
		c = init_cub3d(av[1]);
		if (parsing_name(av[1]) == -1)
			ft_exit(c);
		parsing_core(c);
		if (ac == 3 && !ft_strcmp(av[ac - 1], "-display"))
			print_params();
		init_plane(c);
		parsing_sprite(c);
		mlx_hook(data()->win, 2, 0, &key_press, c);
		mlx_hook(data()->win, 3, 0, &key_release, c);
		mlx_hook(data()->win, 17, 0, &close_prgm, c);
		mlx_loop_hook(data()->ptrwin, &main_loop, c);
		mlx_loop(data()->ptrwin);
		return (0);
	}
	return (msg_error("argument"));
}
