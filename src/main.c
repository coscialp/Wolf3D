/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 12:37:24 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/27 14:34:10 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit_sucess(t_cub3d *c)
{
	close(DATA->fd);
	ft_free_struct(DATA);
	ft_free_tab(MAP->map_2d);
	free(MAP);
	free(COL);
	free(c);
	exit(EXIT_SUCCESS);
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
		if (ac == 3 && !ft_strcmp(av[ac - 1], "display"))
			print_params(c);
		if (!(DATA->ptrwin = mlx_init()))
			ft_exit(c, 3);
		if (!(DATA->win = mlx_new_window(DATA->ptrwin,
		DATA->res_x, DATA->res_y, "Cub3D")))
			ft_exit(c, 3);
		// mlx_loop_hook(DATA->ptrwin, raycast, c);
		// mlx_key_hook(DATA->win, key_press, c);
		// mlx_hook(DATA->win, 17, 0, close_prgm, c);
		// mlx_loop(DATA->ptrwin);
		ft_exit_sucess(c);
	}
	return (msg_error("argument"));
}
