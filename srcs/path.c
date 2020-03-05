/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:25:51 by mbeuil            #+#    #+#             */
/*   Updated: 2019/03/26 16:25:53 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/lem_in.h"

static int	find_room(t_rooms **r1, char *r2)
{
	int	i;

	i = 0;
	if (r1)
	{
		while (r1[i])
		{
			if (ft_strequ(r1[i]->name, r2))
				return (1);
			i++;
		}
	}
	return (0);
}

static int	verif_path(t_farm *farm, char **tab)
{
	if (ft_strequ(tab[0], tab[1]))
		return (0);
	if (!find_room(farm->rooms, tab[0]))
		return (0);
	if (!find_room(farm->rooms, tab[1]))
		return (0);
	return (1);
}

int			add_paths(char *line, t_farm *farm)
{
	int		err;
	char	**tab;

	err = 0;
	if (line[0] == '#' && line[1] == '#')
	{
		if (!(add_command(line, farm)))
			err++;
	}
	else
	{
		if (!(tab = ft_strsplit(line, '-')))
			return (0);
		if (!verif_path(farm, tab))
			err++;
		if (ft_tablen(tab) == 2 && !err)
		{
			if (!fill_paths(farm, tab))
				err++;
		}
		else
			farm->step = 0;
		ft_freetab(tab);
	}
	return (err > 0 ? 0 : 1);
}
