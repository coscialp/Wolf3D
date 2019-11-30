/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin_zero.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 13:24:20 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 13:58:37 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strjoin_zero(char *s1, char *s2)
{
	size_t		lmalloc;
	char		*str;
	size_t		i;
	size_t		ls1;

	i = 0;
	ls1 = ft_strlen(s1);
	lmalloc = ls1 + ft_strlen(s2);
	if (!(str = (char *)ft_calloc(sizeof(char), (lmalloc + 2))))
		return (NULL);
	ft_memcpy(str, s1, ls1);
	ft_memcpy(str + ls1 + 1, s2, ft_strlen(s2) + 1);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (str);
}
