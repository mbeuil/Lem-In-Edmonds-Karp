/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_farm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:31:13 by mbeuil            #+#    #+#             */
/*   Updated: 2019/04/01 19:31:17 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/lem_in.h"

t_farm	*init_farm(void)
{
	t_farm	*farm;

	if (!(farm = (t_farm*)malloc(sizeof(t_farm))))
		return (NULL);
	farm->step = 1;
	farm->n_ants = 0;
	farm->command = NULL;
	farm->n_rooms = 0;
	farm->rooms = NULL;
	farm->start = -1;
	farm->end = -1;
	farm->paths = NULL;
	farm->r_graph = NULL;
	farm->lane = NULL;
	farm->buffer = NULL;
	farm->max_flow = 0;
	farm->round = 0;
	farm->ant = 1;
	return (farm);
}
