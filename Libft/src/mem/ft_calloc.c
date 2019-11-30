/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_calloc.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 10:22:22 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 16:20:47 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t nb, size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(size * nb)))
		return (NULL);
	ft_bzero(ptr, nb * size);
	return (ptr);
}
