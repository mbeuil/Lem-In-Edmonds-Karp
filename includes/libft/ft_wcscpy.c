/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcscpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:49:23 by mbeuil            #+#    #+#             */
/*   Updated: 2018/04/11 13:49:25 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t			*ft_wcscpy(wchar_t *s1, const wchar_t *s2)
{
	int			i;

	i = 0;
	while (s2[i] != L'\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = L'\0';
	return (s1);
}
