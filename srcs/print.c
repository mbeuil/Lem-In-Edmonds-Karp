/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:33:08 by mbeuil            #+#    #+#             */
/*   Updated: 2019/03/26 16:33:09 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/lem_in.h"

static void	send_ants(t_farm *farm)
{
	int	i;

	i = -1;
	while (farm->lane[++i])
		if (!farm->lane[i]->trace[0] && farm->lane[i]->ants)
		{
			farm->lane[i]->trace[0] = farm->ant;
			--farm->lane[i]->ants;
			farm->ant++;
		}
}

static void	print_solution(t_farm *farm)
{
	int	i;
	int	j;
	int	space;

	i = -1;
	space = 0;
	send_ants(farm);
	while (farm->lane[++i])
	{
		j = farm->lane[i]->size;
		while (--j >= 0)
		{
			if (farm->lane[i]->trace[j])
			{
				if (space++)
					ft_printf(" ");
				ft_printf("L%d", farm->lane[i]->trace[j]);
				ft_printf("-%s", farm->lane[i]->node[j]);
				if (farm->lane[i]->node[j + 1])
					farm->lane[i]->trace[j + 1] = farm->lane[i]->trace[j];
				farm->lane[i]->trace[j] = 0;
			}
		}
	}
	ft_printf("\n");
}

static int	init_trace(t_lane *lane)
{
	int	*trace;
	int	j;

	if (!(trace = (int *)malloc(sizeof(int) * lane->size)))
		return (0);
	j = -1;
	while (++j < lane->size)
		trace[j] = 0;
	lane->trace = trace;
	return (1);
}

static void	print_buffer(t_buffer *buffer)
{
	int	i;

	i = -1;
	while (++i < buffer->s && buffer->tab[i])
		ft_printf("%s\n", buffer->tab[i]);
	ft_printf("\n");
}

int			print_farm(t_farm *farm)
{
	int	i;
	int	total_round;

	i = -1;
	total_round = farm->lane[0]->rounds;
	while (farm->lane[++i])
		if (!init_trace(farm->lane[i]))
			return (0);
	print_buffer(farm->buffer);
	while (total_round--)
		print_solution(farm);
	return (1);
}
