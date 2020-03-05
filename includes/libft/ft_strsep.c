/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:24:25 by mbeuil            #+#    #+#             */
/*   Updated: 2017/11/06 18:24:27 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsep(char **stringp, const char *delim)
{
	char	*str;
	char	*ptr;

	if (*stringp == NULL)
		return (NULL);
	str = *stringp;
	if ((ptr = ft_strpbrk(str, delim)))
		*ptr++ = '\0';
	*stringp = ptr;
	return (str);
}
