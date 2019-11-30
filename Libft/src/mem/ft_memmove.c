/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 18:48:12 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 12:24:14 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	int			i;
	char		*d;
	char		*s;

	i = 0;
	if (!(dest && src))
		return (0);
	d = (char *)dest;
	s = (char *)src;
	if (d < s)
	{
		while (n--)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
		while (n--)
			d[n] = s[n];
	return (dest);
}
