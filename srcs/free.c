/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:27:45 by mbeuil            #+#    #+#             */
/*   Updated: 2019/03/26 15:27:46 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/lem_in.h"

void		li_freenode_reverse(t_lane *lane)
{
	int	i;

	i = lane->size;
	while (lane->node[--i])
		if (lane->node[i])
			free(lane->node[i]);
	free(lane->node);
	free(lane);
}

static void	li_freebuffer(t_buffer *buffer)
{
	ft_freetab(buffer->tab);
	free(buffer);
}

void		li_freelane(t_lane **lane)
{
	int	i;

	i = -1;
	while (lane[++i])
	{
		ft_freetab(lane[i]->node);
		free(lane[i]->trace);
		free(lane[i]);
	}
	free(lane);
}

static void	li_freeroom(t_rooms **room)
{
	int				i;

	i = -1;
	while (room[++i])
	{
		if (room[i]->name)
			free(room[i]->name);
		free(room[i]);
	}
	free(room);
}

void		li_freefarm(t_farm *farm)
{
	if (farm)
	{
		if (farm->rooms)
			li_freeroom(farm->rooms);
		if (farm->paths)
			ft_freetab(farm->paths);
		if (farm->buffer)
			li_freebuffer(farm->buffer);
		if (farm->lane)
			li_freelane(farm->lane);
		if (farm->command)
			free(farm->command);
		if (farm->r_graph)
			ft_freetab(farm->r_graph);
		free(farm);
	}
}
