/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:35:48 by mbeuil            #+#    #+#             */
/*   Updated: 2019/03/26 16:35:49 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/lem_in.h"

char	**create_residual_graph(t_farm *farm)
{
	char			**t;
	int				i;
	int				j;

	i = -1;
	if (!(t = (char **)ft_memalloc(sizeof(*t) * (farm->n_rooms + 1))))
		return (NULL);
	while (++i < farm->n_rooms)
	{
		if (!(t[i] = (char *)ft_memalloc(sizeof(**t) * (farm->n_rooms + 1))))
		{
			ft_freetab(t);
			return (NULL);
		}
		ft_memset(t[i], 0 + '0', sizeof(char) * (farm->n_rooms));
		j = -1;
		while (++j < farm->n_rooms)
		{
			if (farm->paths[i][j] == '3')
				t[i][j] = 1 + '0';
		}
	}
	return (t);
}
