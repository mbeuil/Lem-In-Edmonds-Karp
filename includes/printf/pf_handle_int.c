/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 22:26:48 by mbeuil            #+#    #+#             */
/*   Updated: 2017/12/04 11:33:57 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../libft/libft.h"

static intmax_t	get_signed_from_length(va_list *args, t_arg *arg)
{
	intmax_t	nbr;

	nbr = va_arg(*args, intmax_t);
	if (arg->length == hh)
		nbr = (char)nbr;
	else if (arg->length == h)
		nbr = (short int)nbr;
	else if (arg->length == l)
		nbr = (long int)nbr;
	else if (arg->length == ll)
		nbr = (long long int)nbr;
	else if (arg->length == j)
		nbr = (intmax_t)nbr;
	else if (arg->length == z)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

size_t			pf_handle_int(const char **format, va_list *args, t_arg *arg)
{
	intmax_t				nbr;
	char					*prefix;

	(void)format;
	if (arg->got_precision)
		arg->pad_zeroes = 0;
	nbr = get_signed_from_length(args, arg);
	if (nbr < 0 || arg->force_sign || arg->blank_sign)
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			prefix = "-";
		}
		else if (arg->force_sign)
			prefix = "+";
		else if (arg->blank_sign)
			prefix = " ";
		else
			prefix = "";
		return (ft_printf_nbrforceprefix(nbr, "0123456789", arg, prefix));
	}
	else
		return (pf_handle_uint(nbr, arg, "0123456789", NULL));
}
