/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lane.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:23:04 by mbeuil            #+#    #+#             */
/*   Updated: 2019/03/26 16:23:05 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/lem_in.h"

static int		is_same_direct_path(int *visited, int size, int end)
{
	if (size != 0)
		return (0);
	if (!visited[end])
	{
		visited[end] = 1;
		return (0);
	}
	else
		return (1);
}

static int		add_node(char *room, char **lane, int i)
{
	if (!(lane[i - 1] = ft_strdup(room)))
		return (0);
	return (1);
}

static t_lane	*init_lane(char *room, int i)
{
	char	**tmp;
	t_lane	*lane;

	if (!(tmp = (char **)malloc(sizeof(*tmp) * (i + 1))))
		return (NULL);
	if (!(lane = (t_lane *)malloc(sizeof(*lane))))
	{
		free(tmp);
		return (NULL);
	}
	tmp[i] = NULL;
	if (!add_node(room, tmp, i))
	{
		free(tmp);
		free(lane);
		return (NULL);
	}
	lane->trace = NULL;
	lane->node = tmp;
	lane->size = i;
	lane->rounds = 0;
	lane->ants = 0;
	return (lane);
}

static t_lane	*fill_lane(t_farm *farm, int i, int *visited, int x)
{
	int		j;
	t_lane	*lane;

	j = -1;
	while (++j < farm->n_rooms)
		if (farm->r_graph[j][i] >= '2')
		{
			if (j == farm->end && !is_same_direct_path(visited, x, j))
				return (init_lane(farm->rooms[j]->name, ++x));
			else if (!visited[j])
			{
				visited[j] = 1;
				lane = fill_lane(farm, j, visited, ++x);
				if (lane)
				{
					if (!(lane->node[x - 1] = ft_strdup(farm->rooms[j]->name)))
					{
						li_freenode_reverse(lane);
						return (NULL);
					}
				}
				return (lane);
			}
		}
	return (NULL);
}

int				add_lane(t_farm *farm)
{
	int		visited[farm->n_rooms];
	int		i;
	t_lane	**lane;

	i = -1;
	while (++i < farm->n_rooms)
		visited[i] = 0;
	if (!(lane = (t_lane **)malloc(sizeof(*lane) * (farm->max_flow + 1))))
		return (0);
	lane[farm->max_flow] = NULL;
	i = -1;
	while (++i < farm->max_flow)
	{
		if (!(lane[i] = fill_lane(farm, farm->start, visited, 0)))
		{
			li_freelane(lane);
			return (0);
		}
	}
	sort_lane(lane, farm->max_flow);
	dispatch_lane(lane, farm);
	save_lane(lane, farm);
	return (1);
}
