/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:40:25 by mbeuil            #+#    #+#             */
/*   Updated: 2018/04/11 13:40:28 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_isint(char *str)
{
	long long		nbr;

	if (ft_isnumber(str))
	{
		nbr = ft_atoll(str);
		if (nbr > INTMAX || nbr < INTMIN)
			return (0);
		return (1);
	}
	return (0);
}
