/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_uinto.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 22:26:48 by mbeuil            #+#    #+#             */
/*   Updated: 2017/12/04 11:33:57 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../libft/libft.h"

size_t		pf_handle_uinto(uintmax_t nbr,
		t_arg *arg, char *base, char *prefix)
{
	unsigned int			nbr_len;
	unsigned int			nbrstrlen;

	if (arg->got_precision)
		arg->pad_zeroes = 0;
	nbr_len = ft_printf_nbrlen(nbr, base);
	if (arg->got_width && !arg->right_pad && arg->pad_zeroes)
	{
		if (arg->got_precision)
			arg->precision = ft_max(arg->width, arg->precision);
		else
			arg->precision = ft_max(arg->width, nbr_len);
		arg->got_precision = 1;
		arg->got_width = 0;
	}
	nbrstrlen = ft_printf_calc_nbrstrlen(nbr, base, prefix, arg);
	if (arg->got_width && !arg->right_pad)
		ft_printf_width_pad(nbrstrlen, arg->width, ' ');
	if (arg->force_prefix && prefix != NULL && nbr != 0)
		ft_putstr(prefix);
	ft_putnbrbp(nbr, base, arg, nbr_len);
	if (arg->got_width && arg->right_pad)
		ft_printf_width_pad(nbrstrlen, arg->width, ' ');
	return (arg->got_width ? ft_max(nbrstrlen, arg->width) : nbrstrlen);
}
