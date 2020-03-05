/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 05:15:49 by mbeuil            #+#    #+#             */
/*   Updated: 2017/12/04 15:49:36 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;

	i = ft_strlen((char *)s) + 1;
	if (c == 0 && *s == 0)
		return ((char *)s);
	while (i--)
	{
		if (s[i] == c)
			return ((char *)s + i);
	}
	return (NULL);
}
