/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_escape.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 22:26:48 by mbeuil            #+#    #+#             */
/*   Updated: 2017/12/04 11:33:57 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../libft/libft.h"

size_t	pf_handle_escape(const char **format, va_list *args, t_arg *arg)
{
	(void)format;
	(void)args;
	(void)arg;
	if (arg->got_width && !arg->right_pad)
		ft_printf_width_pad(1, arg->width, arg->pad_zeroes ? '0' : ' ');
	ft_putchar('%');
	if (arg->got_width && arg->right_pad)
		ft_printf_width_pad(1, arg->width, ' ');
	return (arg->got_width ? ft_max(arg->width, 1) : 1);
}
