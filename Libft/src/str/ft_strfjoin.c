/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strfjoin.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 16:00:15 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/26 18:19:05 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strfjoin(char *s1, char *s2, int free)
{
	char	*str;

	if (!(str = ft_strjoin(s1, s2)))
		return (0);
	if (free == 1)
		ft_strdel(&s1);
	else if (free == 2)
		ft_strdel(&s2);
	else if (free == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (str);
}
