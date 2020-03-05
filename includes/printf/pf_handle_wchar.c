/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_wchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 22:26:48 by mbeuil            #+#    #+#             */
/*   Updated: 2017/12/04 11:33:57 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../libft/libft.h"

size_t	pf_handle_wchar(const char **format, va_list *args, t_arg *arg)
{
	wchar_t		chr;
	unsigned	chr_len;

	(void)format;
	chr = (wchar_t)va_arg(*args, wchar_t);
	if (chr <= 0x7F)
		chr_len = 1;
	else if (chr <= 0x7FF)
		chr_len = 2;
	else if (chr <= 0xFFFF)
		chr_len = 3;
	else if (chr <= 0x10FFFF)
		chr_len = 4;
	else
		chr_len = 0;
	if (arg->got_width && !arg->right_pad)
		ft_printf_width_pad(chr_len, arg->width, arg->pad_zeroes ? '0' : ' ');
	ft_putwchar(chr);
	if (arg->got_width && arg->right_pad)
		ft_printf_width_pad(chr_len, arg->width, arg->pad_zeroes ? '0' : ' ');
	return (arg->got_width ? ft_max(chr_len, arg->width) : chr_len);
}
