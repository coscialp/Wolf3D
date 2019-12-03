/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 13:50:11 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 13:58:38 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int			char_in_string(char si, char c)
{
	if (si == c)
		return (1);
	return (0);
}

static char			*ft_copy(char *dest, char *src, char c)
{
	int i;

	i = 0;
	while (src[i] && char_in_string(src[i], c) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

static int			ft_size(const char *str, char c)
{
	int i;
	int word;

	i = 0;
	word = 1;
	while (str[i])
	{
		if (char_in_string(str[i], c) == 1)
			word++;
		i++;
	}
	return (word);
}

static int			ft_cpy_tab(char **split, char *str, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (char_in_string(str[i], c) == 1)
			i++;
		if (char_in_string(str[i], c) && char_in_string(str[i + 1], c))
		{
			if (!(split[k] = (char *)ft_calloc(sizeof(char), (j))))
				return (0);
			k++;
		}
		else
		{
			j = 0;
			while (str[i] && char_in_string(str[i + j], c) == 0)
				j++;
			if (!(split[k] = (char *)ft_calloc(sizeof(char), (j + 1))))
				return (0);
			ft_copy(split[k], str + i, c);
			i = i + j;
			k++;
		}
	}
	return (1);
}

char				**ft_split_line(const char *s)
{
	int		i;
	int		k;
	char	*str;
	char	**split;

	k = 0;
	i = ft_size(s, '\n');
	str = (char *)s;
	if (!(split = (char **)ft_calloc(sizeof(char *), (i + 1))))
		return (NULL);
	if (!(ft_cpy_tab(split, str, '\n')))
	{
		while (split[k])
			free(split[k++]);
		free(split);
		return (NULL);
	}
	return (split);
}
