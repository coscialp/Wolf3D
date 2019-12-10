/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 16:46:55 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 16:46:56 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

t_printf	*setup_struct(void)
{
	t_printf *setup;

	if (!(setup = malloc(sizeof(t_printf))))
		return (NULL);
	setup->width = 0;
	setup->option = 0;
	setup->accu = 0;
	setup->zero = 0;
	setup->sign = 0;
	setup->fd = 0;
	setup->return_size = 0;
	ft_bzero(setup->flags, 5);
	return (setup);
}

char		*ft_join_result(char *result, char *tmp, t_printf *pf)
{
	pf->return_size += ft_strlen(tmp);
	if (pf->option == 'c' && pf->zero == 1)
	{
		if (!(result = ft_strjoin_zero(result, tmp)))
			return (NULL);
	}
	else
	{
		if (!(result = ft_strfjoin(result, tmp, 3)))
			return (NULL);
	}
	return (result);
}

char		**ft_set_tmp(const char *str)
{
	char	**tmp;
	size_t	i;
	size_t	j;

	if (!(tmp = malloc(sizeof(char *) * 4)))
		return (NULL);
	i = 1;
	while (ft_isdigit(str[i]) || ft_is_flag(str[i]))
		i++;
	i++;
	j = i;
	while (str[j] && str[j] != '%')
		j++;
	if (!((tmp[0] = ft_strndup(str, i))))
		return (NULL);
	if (!(tmp[1] = ft_strndup(str + i, j - i)))
		return (NULL);
	return (tmp);
}

int			ft_core_printf(const char *s, size_t pos, t_printf *pf, va_list ap)
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
	write(1, result, pos);
	free(result);
	return (pos);
}

int			ft_printf(const char *s, ...)
{
	va_list		ap;
	size_t		pos;
	t_printf	*pf;

	pos = 0;
	va_start(ap, s);
	if (!(pf = setup_struct()))
		return (-1);
	if (!ft_memchr(s, '%', ft_strlen(s)))
	{
		ft_putstr(s);
		va_end(ap);
		free(pf);
		return (ft_strlen(s));
	}
	pos = ft_core_printf(s, pos, pf, ap);
	if (pos == (size_t)-1)
		return (-1);
	va_end(ap);
	free(pf);
	return (pos);
}
