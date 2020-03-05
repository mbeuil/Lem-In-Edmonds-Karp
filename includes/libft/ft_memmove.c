/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:51:30 by mbeuil            #+#    #+#             */
/*   Updated: 2017/12/20 16:50:56 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst2;
	unsigned char	*src2;
	size_t			i;

	i = len - 1;
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (src < dst)
	{
		while (len--)
		{
			dst2[i] = src2[i];
			i--;
		}
	}
	else
		ft_memcpy(dst2, src2, len);
	return (dst2);
}
