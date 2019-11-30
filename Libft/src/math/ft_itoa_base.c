/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 11:42:14 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/26 14:08:05 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base(int n, int ibase)
{
	char		*base;
	static char	buf[12] = {0};
	int			i;
	int			neg;

	i = 10;
	base = "0123456789abcdef";
	if (n == INT_MIN)
		return (ft_strdup(STR_INT_MIN));
	neg = n < 0 ? -1 : 1;
	n = n < 0 ? -n : n;
	while (1)
	{
		buf[i--] = base[n % ibase];
		n /= ibase;
		if (n == 0)
			break ;
	}
	if (neg == -1)
		buf[i] = '-';
	return (neg == -1 ? ft_strdup(buf + i) : ft_strdup(buf + 1 + i));
}
