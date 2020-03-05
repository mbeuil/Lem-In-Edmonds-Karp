/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 22:26:48 by mbeuil            #+#    #+#             */
/*   Updated: 2017/12/04 11:33:57 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../libft/libft.h"

size_t	pf_handle_char(const char **format, va_list *args, t_arg *arg)
{
	(void)format;
	if (arg->length == l)
		return (pf_handle_wchar(format, args, arg));
	else
	{
		if (arg->got_width && !arg->right_pad)
			ft_printf_width_pad(1, arg->width, arg->pad_zeroes ? '0' : ' ');
		ft_putchar(va_arg(*args, int));
		if (arg->got_width && arg->right_pad)
			ft_printf_width_pad(1, arg->width, ' ');
		return (arg->got_width ? ft_max(arg->width, 1) : 1);
	}
}
