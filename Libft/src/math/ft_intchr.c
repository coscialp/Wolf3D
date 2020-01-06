/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_intchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 14:53:06 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 14:55:32 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		*ft_intchr(int *tab, size_t size, int n)
{
	int		i;

	i = 0;
	while (size--)
	{
		if (tab[i] == n)
			return (tab + i);
		i++;
	}
	return (0);
}
