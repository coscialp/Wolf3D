/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stris.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 19:24:43 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 15:36:02 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_stris(char *str, int (*f)(int))
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
