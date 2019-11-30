/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handler_convert.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 14:12:04 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 14:51:54 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_scanf.h"

int		convert_s(t_scanf *sf, char **str)
{
	if (!(*str = ft_strdup(sf->current_arg)))
	{
		ft_strdel(&sf->current_arg);
		return (FAILURE);
	}
	ft_strdel(&sf->current_arg);
	return (SUCESS);
}

int		convert_di(t_scanf *sf, int *nb)
{
	*nb = ft_atoi(sf->current_arg);
	ft_strdel(&sf->current_arg);
	return (SUCESS);
}

int		apply_convert(t_scanf *sf, va_list ap)
{
	sf->return_size += ft_strlen(sf->current_arg);
	if (sf->option == 's')
		return (convert_s(sf, va_arg(ap, char **)));
	if (sf->option == 'd' || sf->option == 'i')
		return (convert_di(sf, va_arg(ap, int *)));
	else
		return (FAILURE);
}
