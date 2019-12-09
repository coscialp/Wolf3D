/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 16:57:05 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 17:04:18 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;
	size_t	len_ptr;

	if (!ptr)
		return (NULL);
	len_ptr = ft_strlen(ptr);
	if (!(new = malloc(size)))
		return (NULL);
	ft_memcpy(new, ptr, len_ptr);
	ft_bzero(new + len_ptr, size - len_ptr);
	ft_memdel(&ptr);
	return (new);
}
