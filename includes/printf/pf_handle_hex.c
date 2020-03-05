/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 22:26:48 by mbeuil            #+#    #+#             */
/*   Updated: 2017/12/04 11:33:57 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../libft/libft.h"

size_t	pf_handle_hex(const char **format, va_list *args, t_arg *arg)
{
	uintmax_t	nbr;

	nbr = ft_printf_get_unsigned_from_length(args, arg);
	if (**format == 'X')
		return (pf_handle_uintx(nbr, arg, "0123456789ABCDEF", "0X"));
	else
		return (pf_handle_uintx(nbr, arg, "0123456789abcdef", "0x"));
}
