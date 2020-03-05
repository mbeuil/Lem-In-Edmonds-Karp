/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:31:54 by mbeuil            #+#    #+#             */
/*   Updated: 2019/04/01 19:31:56 by mbeuil           ###   ########.fr       */
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

int			verif_room(t_farm *farm, char **tab)
{
	if (tab[0][0] != 'L' && !ft_strstr(tab[0], "-")
		&& ft_isnumber(tab[1]) && ft_isnumber(tab[2])
		&& (ft_atol(tab[1]) >= INTMIN && ft_atol(tab[1]) <= INTMAX)
		&& (ft_atol(tab[2]) >= INTMIN && ft_atol(tab[2]) <= INTMAX)
		&& !find_room(farm->rooms, tab[0]))
		return (1);
	else
	{
		farm->step = 0;
		return (0);
	}
}

t_rooms		**dup_struct(t_farm *farm)
{
	t_rooms	**tmp;
	int		i;

	i = 0;
	if (!(tmp = (t_rooms **)malloc(sizeof(*tmp) * (farm->n_rooms + 1))))
		return (NULL);
	tmp[farm->n_rooms] = NULL;
	i = -1;
	while (++i < farm->n_rooms)
		tmp[i] = farm->rooms[i];
	return (tmp);
}
