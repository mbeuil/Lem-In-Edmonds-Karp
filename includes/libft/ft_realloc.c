/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:45:08 by mbeuil            #+#    #+#             */
/*   Updated: 2018/04/11 13:45:11 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	if (!ptr || !(new = ft_memalloc(size)))
		return (NULL);
	ft_memcpy(new, ptr, ft_strlen(ptr));
	free(ptr);
	return (new);
}
