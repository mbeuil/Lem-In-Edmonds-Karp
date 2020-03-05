/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:55:24 by mbeuil            #+#    #+#             */
/*   Updated: 2019/03/26 16:55:25 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/lem_in.h"

void		update_capacity(t_farm *farm, int front, int back)
{
	farm->r_graph[front][back] -= 1;
	farm->r_graph[back][front] += 1;
	farm->rooms[front]->capacity -= 1;
}

static int	has_exception(t_farm *farm, int i, int j)
{
	if (farm->rooms[i]->exception == -1
		|| farm->rooms[i]->exception == j)
		return (0);
	return (1);
}

static int	next_capacity(t_farm *farm, int *visited, int j)
{
	int	i;

	if (farm->rooms[j]->capacity > 0)
		return (1);
	else
	{
		i = -1;
		while (++i < farm->n_rooms)
			if (i != j && !visited[i] && farm->paths[j][i] == '3'
				&& farm->r_graph[j][i] > '1')
			{
				farm->rooms[j]->exception = i;
				return (1);
			}
	}
	return (0);
}

int			verif_node(t_farm *farm, int i, int j, int *visited)
{
	if (visited[j])
		return (0);
	if (farm->paths[i][j] != '3')
		return (0);
	if (farm->r_graph[i][j] == '0')
		return (0);
	if (!(farm->r_graph[i][j] > '1' || next_capacity(farm, visited, j)))
		return (0);
	if (has_exception(farm, i, j))
		return (0);
	return (1);
}
