/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_substr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 15:01:38 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/26 17:38:31 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		l;
	size_t		lmalloc;
	char		*str;

	i = 0;
	l = ft_strlen(s);
	if ((start >= l) || (len == 0))
		return (ft_calloc(sizeof(char), 1));
	lmalloc = (start - l < len ? start - l : len);
	if (!(str = (char*)ft_calloc(sizeof(char), lmalloc + 1)))
		return (NULL);
	while (len--)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	return (str);
}
