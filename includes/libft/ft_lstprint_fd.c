/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:43:09 by mbeuil            #+#    #+#             */
/*   Updated: 2018/04/11 13:43:11 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint_fd(t_list *lst, int fd)
{
	if (lst)
	{
		while (lst)
		{
			ft_putstr_fd(lst->content, fd);
			lst = lst->next;
		}
	}
}
