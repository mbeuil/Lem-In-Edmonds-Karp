/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:37:24 by mbeuil            #+#    #+#             */
/*   Updated: 2018/04/11 13:37:27 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long	count(const char *str, int len)
{
	unsigned long long		ret;

	ret = 0;
	while (str[len] >= '0' && str[len] <= '9')
	{
		ret *= 10;
		ret += str[len] - '0';
		len++;
	}
	return (ret);
}

long						ft_atol(const char *str)
{
	unsigned long long		ret;
	int						neg;
	int						i;

	i = 0;
	ret = 0;
	neg = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	ret = count(str, i);
	if (ret > LONGMAX && neg == 1)
		return (LONGMAX);
	else if (ret > LONGMAX && neg == -1)
		return (-9223372036854775808U);
	else
		return (ret * neg);
}
