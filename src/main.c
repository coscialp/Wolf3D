/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:37:24 by coscialp          #+#    #+#             */
/*   Updated: 2020/03/12 20:45:46 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
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
	c->sprite = malloc(sizeof(t_sprite));
	if (!(c->zbuffer = malloc(sizeof(double) * data()->res_x)))
		ft_exit(c);
}

void	ft_exit_sucess(t_cub3d *c)
{
	close(data()->fd);
	free(c->sprite);
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
	init_windows(c);
}

int		main_loop(t_cub3d *c)
{
	if (c->move)
		move_camera(c, c->move);
	if (c->rotate)
		rotate(c, c->rotate);
	if (c->move_lat)
		move_lat_camera(c, c->move_lat);
	if (player()->life > 100)
		player()->life = 100;
	if (player()->life <= 0)
	{
		ft_dprintf(1, "You are DEAD !\n");
		close_prgm(c);
	}
	parsing_sprite(c);
	// int i = 0;
	// while (i < data()->num_sprite)
	// {
	// 	if (c->sprite[i].type == 6)
	// 	{
	// 		c->sprite[i].x += -player()->dir.x * 0.05;
	// 		c->sprite[i].y += -player()->dir.y * 0.05;
	// 	}
	// 	i++;
	// }
	raycast(c);
	draw_lifebar(c);
	mlx_put_image_to_window(data()->ptrwin, data()->win, c->img.img, 0, 0);
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
	static t_player	player = {{0}, 0, 0, 0};

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
		mlx_hook(data()->win, 2, 0, &key_press, c);
		mlx_hook(data()->win, 3, 0, &key_release, c);
		mlx_hook(data()->win, 17, 0, &close_prgm, c);
		mlx_loop_hook(data()->ptrwin, &main_loop, c);
		mlx_loop(data()->ptrwin);
		return (0);
	}
	return (msg_error("argument"));
}
