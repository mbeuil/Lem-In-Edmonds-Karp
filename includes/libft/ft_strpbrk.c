/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:24:13 by mbeuil            #+#    #+#             */
/*   Updated: 2017/11/06 18:24:14 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *s, const char *charset)
{
	char	*str;

	while (*s)
	{
		while (*charset)
		{
			if ((str = ft_strchr(s, *charset)))
				return (str);
			charset++;
		}
		s++;
	}
	return (NULL);
}
