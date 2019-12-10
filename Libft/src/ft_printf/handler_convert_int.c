/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handler_convert_int.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 15:42:26 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 18:53:45 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_d_converter(int nb, t_printf *pf)
{
	return (ft_itoa_pf(nb, pf));
}

char	*ft_x_converter(unsigned int nb)
{
	char *base;

	base = "0123456789abcdef";
	return (ft_itoa_u_base((nb), base));
}

char	*ft_upx_converter(unsigned int nb)
{
	char *base;

	base = "0123456789ABCDEF";
	return (ft_itoa_u_base((nb), base));
}

char	*ft_u_converter(unsigned int nb)
{
	char *base;

	base = "0123456789";
	return (ft_itoa_u_base((nb), base));
}

char	*ft_f_converter(double nb)
{
	return (ft_ftoa(nb, 5));
}
