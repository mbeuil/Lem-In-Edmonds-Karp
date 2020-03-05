/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:30:18 by mbeuil            #+#    #+#             */
/*   Updated: 2019/04/01 19:30:22 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/lem_in.h"

int	add_command(char *line, t_farm *farm)
{
	char	*tmp;

	if (!(ft_strcmp(line, "##start") && ft_strcmp(line, "##end")))
	{
		if (!farm->command)
		{
			if (!(ft_strcmp(line, "##start")) && farm->start != -1)
				return (0);
			else if (!(ft_strcmp(line, "##end")) && farm->end != -1)
				return (0);
			if (!(tmp = ft_strdup(line)))
				return (0);
			farm->command = tmp;
		}
		else
		{
			farm->step = 0;
			ft_strdel(&farm->command);
		}
	}
	return (1);
}
