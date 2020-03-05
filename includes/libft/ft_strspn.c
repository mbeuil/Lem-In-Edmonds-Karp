/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:48:49 by mbeuil            #+#    #+#             */
/*   Updated: 2018/04/11 13:48:51 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strspn(const char *s, const char *charset)
{
	const char	*ptr;
	const char	*ptr2;

	ptr = s;
	while (*ptr)
	{
		ptr2 = charset;
		while (1)
		{
			if (*ptr == *ptr2)
				break ;
			else if (*ptr2++ == '\0')
				return (ptr - s);
		}
		ptr++;
	}
	return (ptr - s);
}
