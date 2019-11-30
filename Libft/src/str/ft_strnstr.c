/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 15:44:36 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 17:00:04 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str, const char *fnd, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (fnd[i] == '\0')
		return ((char*)str);
	while (i < size && str[i])
	{
		j = 0;
		while (str[i + j] == fnd[j] && i + j < size)
		{
			if (!fnd[j + 1])
				return ((char*)str + i);
			j++;
		}
		i++;
	}
	return (0);
}
