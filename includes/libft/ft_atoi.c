/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 22:21:17 by mbeuil            #+#    #+#             */
/*   Updated: 2017/12/20 17:05:18 by mbeuil           ###   ########.fr       */
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

int							ft_atoi(const char *str)
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
		return (-1);
	else if (ret > LONGMAX && neg == -1)
		return (0);
	else
		return (ret * neg);
}
