/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 11:42:14 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/26 14:03:54 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	static char	buf[12] = {0};
	int			i;
	int			neg;

	i = 10;
	if (n == INT_MIN)
		return (ft_strdup(STR_INT_MIN));
	neg = n < 0 ? -1 : 1;
	n = n < 0 ? -n : n;
	while (1)
	{
		buf[i--] = n % 10 + '0';
		n /= 10;
		if (n == 0)
			break ;
	}
	if (neg == -1)
		buf[i] = '-';
	return (neg == -1 ? ft_strdup(buf + i) : ft_strdup(buf + 1 + i));
}
