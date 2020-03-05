/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lane3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:23:13 by mbeuil            #+#    #+#             */
/*   Updated: 2019/03/26 16:23:14 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/lem_in.h"

void		save_lane(t_lane **lane, t_farm *farm)
{
	if (!farm->lane)
		farm->lane = lane;
	else
	{
		if (farm->lane[0]->rounds > lane[0]->rounds)
		{
			li_freelane(farm->lane);
			farm->lane = lane;
		}
		else
			li_freelane(lane);
	}
}

static void	balance_dispatch(t_lane **lane, int index)
{
	int	i;
	int	j;

	i = index;
	while (i >= 0)
	{
		j = i - 1;
		if (j >= 0 && (lane[j]->rounds < lane[i]->rounds))
		{
			lane[i]->ants -= 1;
			lane[i]->rounds = lane[i]->ants + lane[i]->size - 1;
			lane[j]->ants += 1;
			lane[j]->rounds = lane[j]->ants + lane[j]->size - 1;
			i = index;
		}
		else
			i--;
	}
}

static void	optimize_dispatch(t_lane **lane, int index)
{
	int	i;
	int	j;

	i = index;
	while (i >= 0)
	{
		j = i - 1;
		if (j >= 0 && (lane[j]->rounds - lane[i]->rounds) >= 1)
		{
			lane[i]->ants += 1;
			lane[i]->rounds = lane[i]->ants + lane[i]->size - 1;
			lane[j]->ants -= 1;
			lane[j]->rounds = lane[j]->ants + lane[j]->size - 1;
			i = index;
		}
		else
			i--;
	}
	balance_dispatch(lane, index);
}

void		dispatch_lane(t_lane **lane, t_farm *farm)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	tmp = 0;
	if (!lane[0]->rounds)
	{
		lane[0]->ants = farm->n_ants;
		lane[0]->rounds = lane[0]->ants + lane[0]->size - 1;
	}
	while (lane[i] && lane[i]->node && (lane[0]->rounds > lane[i]->size))
	{
		j = i;
		while (--j >= 0)
		{
			tmp = (lane[j]->rounds - lane[i]->size) / (i + 1);
			lane[i]->rounds = lane[i]->ants + tmp + lane[i]->size - 1;
			lane[j]->ants -= tmp;
			lane[j]->rounds = lane[j]->ants + lane[j]->size - 1;
			lane[i]->ants += tmp;
		}
		optimize_dispatch(lane, i);
		i++;
	}
}

void		sort_lane(t_lane **lane, int max_flow)
{
	int		i;
	t_lane	*tmp;

	i = 0;
	while (i < max_flow - 1)
	{
		if (lane[i]->size > lane[i + 1]->size)
		{
			tmp = lane[i];
			lane[i] = lane[i + 1];
			lane[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}
