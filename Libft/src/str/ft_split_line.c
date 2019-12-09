/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 13:50:11 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 14:42:55 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_copy(char *dest, char *src, char c)
{
	int i;

	i = 0;
	while (src[i] && src[i] != c)
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
		if (str[i] == c)
			word++;
		i++;
	}
	return (word);
}

static int			ft_norme(char *str, char **split, int *i, char c)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (str[*i] && str[*i + j] != c)
		j++;
	if (!(split[k] = (char *)ft_calloc(sizeof(char), (j + 1))))
		return (0);
	ft_copy(split[(k)++], str + *i, c);
	*i = *i + j;
	return (1);
}

static int			ft_cpy_tab(char **split, char *str, char c)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		if (str[i] == c && str[i + 1] == c)
		{
			if (!(split[k++] = (char *)ft_memalloc(sizeof(char))))
				return (0);
		}
		else
		{
			if (!ft_norme(str, split + k, &i, c))
				return (0);
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
