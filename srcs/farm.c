/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:30:42 by mbeuil            #+#    #+#             */
/*   Updated: 2019/04/01 19:30:45 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/lem_in.h"

static void	add_ants(char *line, t_farm *farm)
{
	long ants;

	ants = 0;
	if (ft_isnumber(line))
	{
		ants = ft_atol(line);
		if (ants <= 2147483647 && ants >= -2147483648)
			farm->n_ants = ants;
		farm->step++;
	}
	else
		farm->step = 0;
}

static int	fill_step(t_farm *farm, char *line, int i)
{
	if (!farm->step)
		return (0);
	if (!line[0])
		return (0);
	if (!(line[0] == '#' && line[1] != '#'))
	{
		if (farm->step == 1)
			add_ants(line, farm);
		else if (farm->step == 2)
		{
			if (!add_rooms(line, farm))
				return (0);
		}
		else if (farm->step == 3)
		{
			if (!(add_paths(line, farm)))
				return (0);
		}
	}
	if (!add_buffer(farm, line, i))
		return (0);
	return (1);
}

int			fill_farm(t_farm *farm)
{
	char	*line;
	int		i;
	int		j;
	int		ret;
	int		process;

	j = 0;
	i = 0;
	process = 1;
	while ((ret = get_next_line(0, &line)))
	{
		if (ret == -1)
			return (0);
		if (process)
			process = fill_step(farm, line, i);
		i++;
		ft_strdel(&line);
	}
	if (farm->n_ants <= 0 || farm->start < 0 || farm->end < 0
		|| !farm->rooms || !farm->paths)
		return (0);
	else
		return (1);
}
