/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:31:45 by mbeuil            #+#    #+#             */
/*   Updated: 2019/04/01 19:31:48 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/lem_in.h"

static void		fill_limit(t_farm *farm, t_rooms *room)
{
	if (farm->command)
	{
		if (!(ft_strcmp(farm->command, "##start")))
		{
			if (farm->start < 0)
			{
				room->role = 1;
				farm->start = farm->n_rooms;
			}
			else
				farm->step = 0;
		}
		if (!(ft_strcmp(farm->command, "##end")))
		{
			if (farm->end < 0)
			{
				room->role = 2;
				farm->end = farm->n_rooms;
			}
			else
				farm->step = 0;
		}
	}
	else
		room->role = 0;
}

static t_rooms	*init_room(t_farm *farm, char *name)
{
	t_rooms			*room;

	if (!(room = (t_rooms *)malloc(sizeof(*room))))
		return (NULL);
	room->capacity = 1;
	room->exception = -1;
	if (!(room->name = ft_strdup(name)))
	{
		free(room);
		return (NULL);
	}
	fill_limit(farm, room);
	return (room);
}

static int		fill_room(t_farm *farm, t_rooms **tmp, char **tab)
{
	int	i;
	int	s;

	if (!verif_room(farm, tab))
		return (0);
	free(farm->rooms);
	s = farm->n_rooms + 2;
	if (!(farm->rooms = (t_rooms **)malloc(sizeof(*farm->rooms) * s)))
		return (0);
	farm->rooms[farm->n_rooms + 1] = NULL;
	i = -1;
	while (++i < farm->n_rooms)
		farm->rooms[i] = tmp[i];
	if (!(farm->rooms[i] = init_room(farm, tab[0])))
		return (0);
	farm->n_rooms++;
	return (1);
}

static int		check_room(char *line, t_farm *farm, t_rooms **tmp)
{
	char	**tab;

	if (!(tab = ft_strsplit(line, ' ')))
		return (0);
	if (ft_tablen(tab) == 3)
	{
		if (!fill_room(farm, tmp, tab))
		{
			ft_freetab(tab);
			return (0);
		}
	}
	else
	{
		farm->step++;
		if (!(add_paths(line, farm)))
		{
			ft_freetab(tab);
			return (0);
		}
	}
	ft_strdel(&farm->command);
	ft_freetab(tab);
	return (1);
}

int				add_rooms(char *line, t_farm *farm)
{
	t_rooms	**tmp;

	if (!(tmp = dup_struct(farm)))
		return (0);
	if (line[0] == '#' && line[1] == '#')
	{
		if (!(add_command(line, farm)))
		{
			free(tmp);
			return (0);
		}
	}
	else
	{
		if (!check_room(line, farm, tmp))
		{
			free(tmp);
			return (0);
		}
	}
	free(tmp);
	return (1);
}
