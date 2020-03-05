/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 06:44:28 by mbeuil            #+#    #+#             */
/*   Updated: 2018/01/09 06:44:30 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*uns_to_str(char *str, unsigned long long n, int len, int base)
{
	if (n / base == 0)
	{
		str[--len] = ((n % base) > 9) ? ((n % base) - 10)
		+ 'a' : (n % base) + '0';
		return (str);
	}
	str = uns_to_str(str, n / base, --len, base);
	str[len] = ((n % base) > 9) ? ((n % base) - 10)
	+ 'a' : (n % base) + '0';
	return (str);
}

static int	unslen(unsigned long long n, int base)
{
	int		i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

char		*ft_utoa_base(unsigned long long n, int base)
{
	char	*str;
	int		nlen;

	nlen = unslen(n, base);
	if (!(str = ft_strnew(nlen)))
		return (NULL);
	str = uns_to_str(str, n, nlen, base);
	return (str);
}
