/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_octal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 22:26:48 by mbeuil            #+#    #+#             */
/*   Updated: 2017/12/04 11:33:57 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../libft/libft.h"

size_t	pf_handle_octal(const char **format, va_list *args, t_arg *arg)
{
	uintmax_t		nbr;
	unsigned int	w;

	w = arg->width;
	(void)format;
	nbr = ft_printf_get_unsigned_from_length(args, arg);
	if (arg->force_prefix && nbr == 0
		&& arg->got_precision && arg->precision == 0)
	{
		if (arg->got_width && !arg->right_pad)
			ft_printf_width_pad(1, arg->width, arg->pad_zeroes ? '0' : ' ');
		ft_putstr("0");
		if (arg->got_width && arg->right_pad)
			ft_printf_width_pad(1, arg->width, ' ');
		return (arg->got_width ? ft_max(arg->width, 1) : 1);
	}
	else if (arg->force_prefix && nbr != 0)
	{
		if (!(ft_printf_nbrlen(nbr, "01234567") < w
			&& arg->pad_zeroes && !arg->got_precision))
			arg->got_precision = 1;
		arg->precision = ft_max(arg->precision,
			ft_printf_nbrlen(nbr, "01234567") + 1);
	}
	return (pf_handle_uinto(nbr, arg, "01234567", NULL));
}
