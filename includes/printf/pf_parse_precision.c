/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 22:26:48 by mbeuil            #+#    #+#             */
/*   Updated: 2017/12/04 11:33:57 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../libft/libft.h"

const char	*pf_parse_precision(const char **format, t_arg *arg)
{
	if (**format == '.')
		arg->precision = 0;
	if (**format == '.')
	{
		(*format)++;
		while (ft_isdigit(**format))
			arg->precision = arg->precision * 10 + (*(*format)++ - '0');
		arg->got_precision = 1;
		return (*format);
	}
	else
		return (*format);
}
