/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbrbpx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 11:40:53 by mbeuil            #+#    #+#             */
/*   Updated: 2018/10/31 11:40:59 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../libft/libft.h"

void	ft_putnbrbp(uintmax_t nbr, char *base, t_arg *arg, unsigned nbr_len)
{
	if (arg->got_precision)
		ft_printf_width_pad(nbr_len, arg->precision, base[0]);
	if (nbr == 0 && arg->got_precision && arg->precision == 0)
		return ;
	else
		ft_putnbrbase(nbr, base);
}
