/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strisdigit.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 19:24:43 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 19:33:24 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisdigit(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_isspace(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
