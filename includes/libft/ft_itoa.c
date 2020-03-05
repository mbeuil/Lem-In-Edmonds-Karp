/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:29:23 by mbeuil            #+#    #+#             */
/*   Updated: 2017/12/20 17:06:06 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*nnumber(int n, int i)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	if (n == -2147483648)
	{
		str[--i] = 8 + '0';
		n = n / 10;
	}
	n = n * -1;
	str[0] = '-';
	while (n)
	{
		str[--i] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

static char		*pnumber(int n, int i)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	while (n)
	{
		str[--i] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

static int		cpt(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;

	if (n == 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
	}
	else if (n < 0)
		str = nnumber(n, cpt(n) + 1);
	else
		str = pnumber(n, cpt(n));
	return (str);
}
