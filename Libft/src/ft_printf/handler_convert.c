/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handler_convert.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 15:40:51 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/23 15:41:31 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_c_converter(int nb, t_printf *pf)
{
	char *c;

	if (!(c = malloc(sizeof(char) * 2)))
		return (NULL);
	c[0] = nb;
	c[1] = 0;
	if (nb == 0)
	{
		pf->zero = 1;
		pf->return_size++;
	}
	if (pf->width != 0 && nb == 0)
		pf->width -= 1;
	return (c);
}

char	*ft_s_converter(char *str, size_t accu, char *flags)
{
	if (!str)
		str = "(null)";
	if (ft_strchr(flags, '.') && accu < ft_strlen(str))
		return (ft_strndup(str, accu));
	return (ft_strdup(str));
}

char	*ft_pourcent_converter(void)
{
	char *c;

	if (!(c = malloc(sizeof(char) * 2)))
		return (NULL);
	c[0] = '%';
	c[1] = 0;
	return (c);
}

char	*ft_p_converter(long long address, t_printf *pf)
{
	char	*s;

	if (ft_strchr(pf->flags, '.') && !address)
		return (ft_strdup("0x"));
	s = ft_itoa_ll_base(address, "0123456789abcdef");
	if (ft_strchr(pf->flags, '0'))
	{
		free(s);
		return (ft_strdup("0x"));
	}
	return (ft_strfjoin("0x", s, 2));
}
