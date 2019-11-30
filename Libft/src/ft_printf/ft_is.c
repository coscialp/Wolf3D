/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_is.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 15:46:28 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/23 15:47:28 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_is_pourcent(char c)
{
	return (c == '%');
}

int		ft_is_option(char c)
{
	char	*options;
	int		i;

	i = 0;
	options = "cspdiuxX%";
	while (options[i])
	{
		if (options[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_is_in_flags(char c, t_printf *pf)
{
	return (ft_strchr(pf->flags, c) != 0);
}

int		ft_is_flag(char c)
{
	char	*flags;
	int		i;

	i = 0;
	flags = "-0.*";
	while (flags[i])
	{
		if (flags[i] == c)
			return (1);
		i++;
	}
	return (0);
}
