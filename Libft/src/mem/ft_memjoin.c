/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 16:58:17 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 15:03:00 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(void *s1, void *s2, size_t size1, size_t size2)
{
	void	*ptr;

	ptr = NULL;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		if (!(ptr = ft_memalloc(size2 + 1)))
			return (NULL);
		return (ft_memcpy(ptr, s2, size2));
	}
	if (!s2)
	{
		if (!(ptr = ft_memalloc(size1 + 1)))
			return (NULL);
		return (ft_memcpy(ptr, s1, size1));
	}
	if (!(ptr = ft_memalloc(size1 + size2 + 1)))
		return (NULL);
	ft_memcpy(ptr, s1, size1);
	ft_memcpy(ptr + size1, s2, size2 + 1);
	return (ptr);
}
