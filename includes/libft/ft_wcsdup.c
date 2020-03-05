/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 02:57:34 by mbeuil            #+#    #+#             */
/*   Updated: 2018/01/08 02:57:38 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t			*ft_wcsdup(const wchar_t *s)
{
	wchar_t		*dst;

	if (!(dst = (wchar_t *)malloc(sizeof(*dst) * (ft_wcslen(s) + 1))))
		return (NULL);
	return (ft_wcscpy(dst, s));
}
