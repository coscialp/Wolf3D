/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stris.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 19:24:43 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 17:37:54 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_stris(char *str, int (*f)(int))
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!(*f)(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
