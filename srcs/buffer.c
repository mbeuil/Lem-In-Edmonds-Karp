/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:29:47 by mbeuil            #+#    #+#             */
/*   Updated: 2019/04/01 19:30:03 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/lem_in.h"

static t_buffer	*init_buffer(void)
{
	t_buffer	*buffer;

	if (!(buffer = (t_buffer *)malloc(sizeof(*buffer))))
		return (NULL);
	buffer->tab = NULL;
	buffer->s = 0;
	return (buffer);
}

int				add_buffer(t_farm *farm, char *line, int i)
{
	char	**t;
	int		j;

	if (!farm->buffer && !(farm->buffer = init_buffer()))
		return (0);
	if (i + 1 > farm->buffer->s)
	{
		if (!(t = (char **)ft_memalloc(sizeof(*t) * (farm->buffer->s + 201))))
			return (0);
		j = -1;
		while (++j < farm->buffer->s && farm->buffer->tab[j])
			if (!(t[j] = ft_strdup(farm->buffer->tab[j])))
			{
				ft_freetab(t);
				return (0);
			}
		if (farm->buffer->tab)
			ft_freetab(farm->buffer->tab);
		farm->buffer->tab = t;
		farm->buffer->s += 200;
	}
	if (!(farm->buffer->tab[i] = ft_strdup(line)))
		return (0);
	return (1);
}
