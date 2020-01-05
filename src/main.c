/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 12:37:24 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/05 14:24:22 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit_sucess(t_cub3d *c)
{
	close(c->data.fd);
	ft_free_struct(c->data);
	ft_free_tab(c->map.map_2d);
	free(c);
	exit(EXIT_SUCCESS);
}

void	init_plane(t_cub3d *c)
{
	if (c->map.compass == 'W')
	{
		c->data.plane.x = -0.66;
		c->data.plane.y = 0;
	}
	else if (c->map.compass == 'E')
	{
		c->data.plane.x = 0.66;
		c->data.plane.y = 0;
	}
	else if (c->map.compass == 'N')
	{
		c->data.plane.x = 0;
		c->data.plane.y = 0.66;
	}
	else if (c->map.compass == 'S')
	{
		c->data.plane.x = 0;
		c->data.plane.y = -0.66;
	}
	c->movspeed = 0.075;
	c->rotspeed = 0.04;
}

int		main_loop(t_cub3d *c)
{
	if (c->move)
		move_camera(c, c->move);
	if (c->rotate)
		rotate(c, c->rotate);
	if (c->move_y)
		move_y_camera(c, c->move_y);
	raycast(c);
	mlx_put_image_to_window(c->data.ptrwin, c->data.win, c->img.img, 0, 0);
	return (0);
}

void	init_windows(t_cub3d *c)
{
	if (!(c->data.ptrwin = mlx_init()))
		ft_exit(c);
	if (!(c->data.win = mlx_new_window(c->data.ptrwin,
	c->data.res_x, c->data.res_y, "Cub3D")))
		ft_exit(c);
	c->img.img = mlx_new_image(c->data.ptrwin,
	c->data.res_x, c->data.res_y);
	c->img.ptr = (int *)mlx_get_data_addr(c->img.img, &c->img.bpp,
	&c->img.size_line, &c->img.endian);
	loading_all_tex(c);
	c->move_cam = 0;
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
		if (ac == 3 && !ft_strcmp(av[ac - 1], "display"))
			print_params(c);
		init_plane(c);
		init_windows(c);
		mlx_hook(c->data.win, 2, 0, &key_press, c);
		mlx_hook(c->data.win, 3, 0, &key_release, c);
		mlx_hook(c->data.win, 17, 0, &close_prgm, c);
		mlx_loop_hook(c->data.ptrwin, &main_loop, c);
		mlx_loop(c->data.ptrwin);
		ft_exit_sucess(c);
	}
	return (msg_error("argument"));
}
