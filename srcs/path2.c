/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:37:12 by mbeuil            #+#    #+#             */
/*   Updated: 2019/03/26 16:37:16 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/lem_in.h"

static void	fill_diagonal(t_rooms **room, char **paths)
{
	int				i;

	i = -1;
	while (room[++i])
		paths[i][i] = room[i]->role + '0';
}

static void	fill_tab(char **paths, int i, int j)
{
	paths[i][j] = 3 + '0';
	paths[j][i] = 3 + '0';
}

static int	get_index(t_rooms **r1, char *r2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!r1 || !r2)
		return (-1);
	while (r1[i])
	{
		if (ft_strequ(r1[i]->name, r2))
			return (i);
		i++;
	}
	return (-1);
}

static char	**init_paths(t_farm *farm)
{
	char	**paths;
	int		i;

	i = -1;
	if (!(paths = (char **)malloc(sizeof(*paths) * (farm->n_rooms + 1))))
		return (NULL);
	paths[farm->n_rooms] = NULL;
	while (++i < farm->n_rooms)
	{
		if (!(paths[i] = (char *)malloc(sizeof(**paths) * (farm->n_rooms + 1))))
		{
			ft_freetab(paths);
			return (NULL);
		}
		ft_memset(paths[i], 0 + '0', sizeof(char) * (farm->n_rooms));
	}
	fill_diagonal(farm->rooms, paths);
	return (paths);
}

int			fill_paths(t_farm *farm, char **room)
{
	int	i;
	int	j;

	if (!farm->paths)
	{
		if (!(farm->paths = init_paths(farm)))
			return (0);
	}
	if ((i = get_index(farm->rooms, room[0])) < 0)
		return (0);
	if ((j = get_index(farm->rooms, room[1])) < 0)
		return (0);
	fill_tab(farm->paths, i, j);
	return (1);
}
