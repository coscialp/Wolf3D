/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 10:12:14 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 08:42:10 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	if (c == 0)
		return ((char *)str + ft_strlen(str));
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
