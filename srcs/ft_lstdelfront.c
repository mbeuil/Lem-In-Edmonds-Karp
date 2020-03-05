/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelfront.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:14:48 by mbeuil            #+#    #+#             */
/*   Updated: 2019/03/26 16:14:52 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/lem_in.h"

void	ft_lstdelfront(t_list **queue)
{
	t_list		*tmp;

	tmp = (*queue)->next;
	ft_lstdelone(queue, &ft_lstfree);
	*queue = tmp;
}
