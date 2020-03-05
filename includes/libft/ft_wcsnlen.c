/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:50:03 by mbeuil            #+#    #+#             */
/*   Updated: 2018/04/11 13:50:05 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wcsnlen(const wchar_t *s, size_t maxlen)
{
	size_t		i;

	i = 0;
	while (s[i] != L'\0' && i < maxlen)
		i++;
	return (i);
}