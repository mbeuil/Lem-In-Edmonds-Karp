/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:15:40 by mbeuil            #+#    #+#             */
/*   Updated: 2019/03/26 16:15:43 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/lem_in.h"

int			main(void)
{
	t_farm	*farm;

	if (!(farm = init_farm()))
		ft_printf("Error\n");
	else
	{
		if (fill_farm(farm))
		{
			if (!resolve_lemin(farm))
				ft_printf("Error\n");
			else
			{
				if (!print_farm(farm))
					ft_printf("Error\n");
			}
		}
		else
			ft_printf("Error\n");
	}
	li_freefarm(farm);
	return (0);
}
