/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 18:44:20 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 16:16:08 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned const char	*s;
	unsigned char		*d;
	size_t				i;

	i = 0;
	s = (const unsigned char*)src;
	d = (unsigned char *)dest;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == c)
			return (d + i + 1);
		i++;
	}
	return (0);
}
