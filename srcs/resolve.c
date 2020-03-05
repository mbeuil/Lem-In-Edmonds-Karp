/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:55:17 by mbeuil            #+#    #+#             */
/*   Updated: 2019/03/26 16:55:18 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/lem_in.h"

static int	iterative_bfs(int *vst, int *parent, t_list **queue, t_farm *farm)
{
	t_list		*new;
	int			i;
	int			j;

	j = -1;
	i = *(int *)(*queue)->content;
	while (++j < farm->n_rooms)
		if (verif_node(farm, i, j, vst))
		{
			vst[j] = 1;
			parent[j] = i;
			if (j == farm->end)
			{
				ft_lstdel(queue, &ft_lstfree);
				return (1);
			}
			if (!(new = ft_lstnew(&j, sizeof(int))))
			{
				ft_lstdel(queue, &ft_lstfree);
				return (0);
			}
			ft_lstaddback(queue, new);
		}
	ft_lstdelfront(queue);
	return (1);
}

static int	bfs(t_farm *farm, int *parent)
{
	t_list	*queue;
	int		visited[farm->n_rooms];
	int		i;

	i = -1;
	while (++i < farm->n_rooms)
		visited[i] = 0;
	if (!(queue = ft_lstnew(&farm->start, sizeof(int))))
		return (0);
	visited[farm->start] = 1;
	parent[farm->start] = -1;
	while (queue)
	{
		if (!iterative_bfs(visited, parent, &queue, farm))
			return (0);
	}
	return (visited[farm->end]);
}

static int	edmond_karp(t_farm *farm)
{
	int	parent[farm->n_rooms];
	int	back;
	int	front;
	int	ret;

	while ((farm->max_flow < farm->n_ants) && (ret = bfs(farm, parent)))
	{
		if (!ret)
			return (0);
		back = farm->end;
		while (back != farm->start)
		{
			front = parent[back];
			update_capacity(farm, front, back);
			back = front;
		}
		farm->max_flow += 1;
		if (!add_lane(farm))
			return (0);
	}
	if (!farm->lane)
		return (0);
	return (1);
}

int			resolve_lemin(t_farm *farm)
{
	if (!(farm->r_graph = create_residual_graph(farm)))
		return (0);
	if (!edmond_karp(farm))
		return (0);
	return (1);
}
