/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_analyser.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/29 11:17:15 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/23 15:48:00 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_analyser(char *tmp, t_printf *pf, va_list ap)
{
	tmp++;
	pf->option = 0;
	if (!(tmp = ft_new_fmt(tmp, pf)))
		return (NULL);
	tmp = ft_set_width(tmp, pf, ap, 0);
	pf->option = tmp[0];
	if (!(tmp = ft_router(tmp + 1, pf, ap)))
		return (NULL);
	return (tmp);
}

char	*ft_router(char *str, t_printf *pf, va_list ap)
{
	char	*tmp;

	if (!(tmp = ft_apply_convert(pf, ap)))
		return (NULL);
	if (!(tmp = ft_apply_flags(tmp, pf)))
		return (NULL);
	if (!(str = ft_strfjoin(tmp, str, 1)))
		return (NULL);
	ft_bzero(&pf->width, sizeof(size_t) * 2);
	return (str);
}
