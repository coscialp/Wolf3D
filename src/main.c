/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 12:37:24 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 15:50:03 by coscialp    ###    #+. /#+    ###.fr     */
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
		c->data.plane.y = -0;
	}
	else if (c->map.compass == 'E')
	{
		c->data.plane.x = 0.66;
		c->data.plane.y = 0;
	}
	else if (c->map.compass == 'N')
	{
		c->data.plane.x = 0;
		c->data.plane.y = -0.66;
	}
	else if (c->map.compass == 'S')
	{
		c->data.plane.x = 0;
		c->data.plane.y = 0.66;
	}
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
		if (!(c->data.ptrwin = mlx_init()))
			ft_exit(c);
		if (!(c->data.win = mlx_new_window(c->data.ptrwin,
		c->data.res_x, c->data.res_y, "Cub3D")))
			ft_exit(c);
		raycast(c);
		mlx_key_hook(c->data.win, key_press, c);
		mlx_hook(c->data.win, 17, 0, close_prgm, c);
		mlx_loop(c->data.ptrwin);
		ft_exit_sucess(c);
	}
	return (msg_error("argument"));
}
