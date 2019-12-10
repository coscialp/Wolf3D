/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 12:37:24 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 20:17:34 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit_sucess(t_cub3d *c)
{
	close(c->data->fd);
	ft_free_struct(c->data);
	ft_free_tab(c->map->map_2d);
	free(c->map);
	free(c->color);
	free(c);
	exit(EXIT_SUCCESS);
}

int		key_press(int keycode, t_cub3d *c)
{
	if (keycode == 53)
	{
		mlx_destroy_window(c->data->ptrwin, c->data->win);
		ft_exit_sucess(c);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_cub3d	*c;

	if (ac >= 2 && ac <= 3)
	{
		c = init_cub3d(av[1]);
		if (parsing_name(av[1]) == -1)
			ft_exit(c, 1);
		parsing_core(c);
		if (ac == 3 && !ft_strcmp(av[ac - 1], "mabitebug"))
			print_params(c->data, c->map);
		if (!(c->data->ptrwin = mlx_init()))
			ft_exit(c, 3);
		if (!(c->data->win = mlx_new_window(c->data->ptrwin,
		c->data->res_x, c->data->res_y, "Cub3D")))
			ft_exit(c, 3);
		mlx_key_hook(c->data->win, key_press, c);
		mlx_loop(c->data->ptrwin);
		ft_exit_sucess(c);
	}
	return (msg_error("argument"));
}
