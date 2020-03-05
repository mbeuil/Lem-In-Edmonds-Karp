/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:06:23 by mbeuil            #+#    #+#             */
/*   Updated: 2017/12/20 17:00:40 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		nchar(const char *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] != sep && str[i] != '\0')
		i++;
	return (i);
}

static int		nword(const char *str, char sep)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] != sep && (str[i + 1] == sep || str[i + 1] == '\0'))
			word++;
		i++;
	}
	return (word);
}

static void		fill_tab(char **dest, const char *s, char sep)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[k])
	{
		j = 0;
		while (s[k] == sep)
			k++;
		while (s[k] != sep && s[k] != '\0')
			dest[i][j++] = s[k++];
		while (s[k] == sep)
			k++;
		if (nword(s, sep) != 0)
			dest[i++][j] = '\0';
	}
	dest[i] = 0;
}

char			**ft_strsplit(char const *str, char c)
{
	char	**dest;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	if (!(dest = (char **)malloc(sizeof(*dest) * (nword(str, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < nword(str, c))
	{
		while (str[j] == c)
			j++;
		if (!(dest[i] = malloc(sizeof(char) * (nchar(str + j, c) + 1))))
			return (NULL);
		i++;
		j = j + nchar(str + j, c);
	}
	fill_tab(dest, str, c);
	return (dest);
}
