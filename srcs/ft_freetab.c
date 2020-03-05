/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:35:19 by mbeuil            #+#    #+#             */
/*   Updated: 2019/03/26 15:35:22 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/lem_in.h"

void	ft_freetab(char **tab)
{
	int i;

	i = 0;
	if (tab)
	{
		i = ft_tablen(tab);
		while (i >= 0)
		{
			free(tab[i]);
			i--;
		}
		free(tab);
	}
}