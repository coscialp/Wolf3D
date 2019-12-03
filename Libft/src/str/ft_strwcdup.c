/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strwcdup.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 18:08:35 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 18:17:27 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strwcdup(char *src, char c)
{
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] == c)
			j++;
		i++;
	}
	if (!(dest = (char *)malloc(sizeof(char) * (i - j) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] == c)
			i++;
		dest[j++] = src[i++];
	}
	dest[j] = 0;
	return (dest);
}
