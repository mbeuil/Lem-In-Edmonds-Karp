/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 21:34:26 by mbeuil            #+#    #+#             */
/*   Updated: 2017/12/20 17:38:59 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while ((unsigned char)s1[i] && \
		(unsigned char)s1[i] == (unsigned char)s2[i] && \
		i < (n - 1))
		i++;
	if (!n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
