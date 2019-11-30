/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_stdin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 14:43:48 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 15:06:05 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_scanf.h"

char				*next_line(char *str, char **line, size_t i, int *end)
{
	if (str && str[i])
	{
		while (str[i] != '\n' && str[i])
			i++;
		*line = (i == 0) ? ft_strdup("") : ft_substr(str, 0, i);
		*end = 1;
		return (*line);
	}
	*end = 1;
	return (ft_strdup(""));
}

char				*read_line(char *str, char *buf)
{
	int				ret;
	char			*tmp;

	while ((ret = read(0, buf, BUFFER_SIZE)) != 0)
	{
		if (ret < 0)
			return ((char *)-1);
		if (!str)
			if (!(str = ft_strdup("")))
				return ((char *)-1);
		buf[ret] = '\0';
		if (!(tmp = ft_strfjoin(str, buf, 1)))
			return ((char *)-1);
		str = tmp;
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (str);
}

int					read_stdin(char **line)
{
	int				end;
	static char		*str;
	char			buf[BUFFER_SIZE + 1];

	end = 0;
	if (BUFFER_SIZE <= 0 || !line)
	{
		if (*line)
			*line = NULL;
		return (-1);
	}
	if (((str = read_line(str, buf)) == (char *)-1))
	{
		if (*line)
			*line = NULL;
		return (-1);
	}
	*line = next_line(str, line, 0, &end);
	if (end == 1)
		ft_strdel(&str);
	return (end != 1);
}
