/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 02:56:40 by mbeuil            #+#    #+#             */
/*   Updated: 2018/01/08 02:56:42 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t			*ft_wcsndup(const wchar_t *s1, size_t n)
{
	wchar_t		*dst;
	size_t		len;

	len = ft_wcsnlen(s1, n);
	if (!(dst = (wchar_t *)malloc(sizeof(*dst) * (len + 1))))
		return (NULL);
	dst[len] = L'\0';
	return (ft_wcsncpy(dst, s1, n));
}
