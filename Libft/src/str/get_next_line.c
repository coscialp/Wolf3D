/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 12:50:03 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 13:30:09 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char				*next_line(char *str, char **line, size_t i, int *end)
{
	char			*tmp;

	if (str && str[i])
	{
		while (str[i] != '\n' && str[i])
			i++;
		if (str[i] == '\n')
		{
			*line = ft_substr(str, 0, i);
			tmp = ft_strdup(str + i + 1);
			ft_strcpy(str, tmp);
			ft_strdel(&tmp);
			return (*line);
		}
		else
		{
			*line = ft_substr(str, 0, i);
			tmp = ft_strdup(str + i);
			ft_strcpy(str, tmp);
			ft_strdel(&tmp);
			return (*line);
		}
	}
	*end = 1;
	return (NULL);
}

char				*read_line(char **str, char *buf, int fd)
{
	int				ret;
	char			*tmp;

	while ((ret = read(fd, buf, BUFFER_SIZE)) != 0)
	{
		if (ret < 0)
			return ((char *)-1);
		if (!str[fd])
			if (!(str[fd] = ft_strdup("")))
				return ((char *)-1);
		buf[ret] = '\0';
		if (!(tmp = ft_strfjoin(str[fd], buf, 1)))
			return ((char *)-1);
		str[fd] = tmp;
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (str[fd]);
}

int					get_next_line(int fd, char **line)
{
	int				end;
	static char		*str[256];
	char			buf[BUFFER_SIZE + 1];

	end = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line || fd >= 256)
	{
		if (*line)
			*line = NULL;
		return (-1);
	}
	if (((str[fd] = read_line(str, buf, fd)) == (char *)-1))
	{
		if (*line)
			*line = NULL;
		return (-1);
	}
	*line = next_line(str[fd], line, 0, &end);
	if (end == 1)
		ft_strdel(&str[fd]);
	return (end != 1);
}
