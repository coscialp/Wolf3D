/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_scanf.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 17:45:28 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 15:04:08 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_scanf.h"

int				check_arg(size_t *i, size_t *j, char *fmt, t_scanf *sf)
{
	while (fmt[*i] && fmt[*i] != '%')
		if (fmt[(*i)++] != sf->arg[(*j)++])
			return (FAILURE);
	if (fmt[*i] == '%' && fmt[*i + 1])
	{
		sf->option = fmt[*i + 1];
		sf->end_arg = fmt[*i + 2];
	}
	return (SUCESS);
}

int				core_parser(size_t *i, size_t *j, char *fmt, t_scanf *sf)
{
	while (fmt[*i] && fmt[*i] != '%')
		if (fmt[(*i)++] != sf->arg[(*j)++])
			return (FAILURE);
	if (fmt[*i] == '%' && fmt[*i + 1])
	{
		sf->option = fmt[*i + 1];
		sf->end_arg = fmt[*i + 2];
	}
	while (sf->arg[*j] != sf->end_arg)
		if (!sf->arg[(*j)++])
			return (FAILURE);
	return (SUCESS);
}

int				parser(char *fmt, char *arg, t_scanf *sf, va_list ap)
{
	size_t		i;
	size_t		k;
	size_t		j;

	i = 0;
	j = 0;
	k = 0;
	while (fmt[i])
	{
		if (check_arg(&i, &j, fmt, sf) == FAILURE)
			return (FAILURE);
		if (core_parser(&i, &j, fmt, sf) == FAILURE)
			return (FAILURE);
		sf->current_arg = ft_substr(arg, k, j - k);
		i += 2;
		k = j + 1;
		if (apply_convert(sf, ap) == FAILURE)
			return (FAILURE);
	}
	return (SUCESS);
}

t_scanf			*init_struct(void)
{
	t_scanf		*sf;

	if (!(sf = (t_scanf *)malloc(sizeof(t_scanf) * 1)))
		return (NULL);
	sf->option = 0;
	sf->end_arg = 0;
	sf->arg = NULL;
	sf->current_arg = NULL;
	sf->return_size = 0;
	return (sf);
}

int				ft_scanf(char *fmt, ...)
{
	t_scanf		*sf;
	va_list		ap;
	size_t		i;

	va_start(ap, fmt);
	if (!(sf = init_struct()))
		return (FAILURE);
	if (read_stdin(&sf->arg) == -1)
	{
		ft_memdel((void **)&sf);
		return (FAILURE);
	}
	if (parser(fmt, sf->arg, sf, ap) == -1)
	{
		ft_strdel(&sf->arg);
		ft_memdel((void **)&sf);
		return (FAILURE);
	}
	ft_strdel(&sf->arg);
	i = sf->return_size;
	ft_memdel((void **)&sf);
	return (i);
}
