/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dprintf.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 15:49:20 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/23 15:54:08 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_core_dprintf(const char *s, size_t pos, t_printf *pf, va_list ap)
{
	char		**tmp;
	char		*result;

	pos = (char *)ft_memchr(s, '%', ft_strlen(s)) - s;
	result = ft_strndup(s, pos);
	s += pos;
	while (*s)
	{
		if (!(tmp = ft_set_tmp(s)))
			return (-1);
		s += ft_strlen(tmp[0]) + ft_strlen(tmp[1]);
		if (!(tmp[2] = ft_strfjoin(tmp[0], tmp[1], 3)))
			return (-1);
		if (!(tmp[3] = ft_analyser(tmp[2], pf, ap)))
			return (-1);
		free(tmp[2]);
		if (!(result = ft_join_result(result, tmp[3], pf)))
			return (-1);
		free(tmp);
	}
	pos += pf->return_size;
	write(pf->fd, result, pos);
	free(result);
	return (pos);
}

int			ft_dprintf(int fd, const char *s, ...)
{
	va_list		ap;
	size_t		pos;
	t_printf	*pf;

	pos = 0;
	va_start(ap, s);
	if (!(pf = setup_struct()))
		return (-1);
	pf->fd = fd;
	if (!ft_memchr(s, '%', ft_strlen(s)))
	{
		ft_putstr_fd(s, fd);
		va_end(ap);
		free(pf);
		return (ft_strlen(s));
	}
	pos = ft_core_dprintf(s, pos, pf, ap);
	if (pos == (size_t)-1)
		return (-1);
	va_end(ap);
	free(pf);
	return (pos);
}
