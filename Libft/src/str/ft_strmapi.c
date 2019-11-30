/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 15:33:10 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 16:07:59 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if (!(str = ft_strdup(s)))
		return (NULL);
	while (str[i] != '\0')
	{
		str[i] = (*f)(i, str[i]);
		i++;
	}
	return (str);
}
