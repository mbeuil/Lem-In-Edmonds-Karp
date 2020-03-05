/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:19:39 by mbeuil            #+#    #+#             */
/*   Updated: 2017/12/04 12:05:06 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		while (s2[j] == s1[i + j] && (i + j) < n)
		{
			j++;
			if (s2[j] == '\0')
				return ((char *)s1 + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
