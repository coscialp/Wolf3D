/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_int_tab.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/03 19:15:10 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 13:09:22 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_float_tab(double *tab, int size)
{
	int		i;
	double	buff;

	i = 0;
	while (i < size - 1)
	{
		i++;
		if (tab[i - 1] > tab[i])
		{
			buff = tab[i - 1];
			tab[i - 1] = tab[i];
			tab[i] = buff;
			i = 0;
		}
	}
}
