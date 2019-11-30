/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_ll_base.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 14:31:25 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/23 14:31:28 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_ll_base(unsigned long n, char *base)
{
	static char	buf[18] = {0};
	int			i;
	int			lbase;

	lbase = ft_strlen(base);
	i = 16;
	while (1)
	{
		buf[i--] = base[n % lbase];
		n /= lbase;
		if (n == 0)
			break ;
	}
	return (ft_strdup(buf + 1 + i));
}
