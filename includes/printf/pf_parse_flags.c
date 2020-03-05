/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 22:26:48 by mbeuil            #+#    #+#             */
/*   Updated: 2017/12/04 11:33:57 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../libft/libft.h"

const char	*pf_parse_flags(const char **format, t_arg *arg)
{
	if (**format == '#' || **format == '0' || **format == '-' || **format == '+'
		|| **format == ' ')
	{
		if (**format == '#')
			arg->force_prefix = 1;
		else if (**format == '0')
			arg->pad_zeroes = 1;
		else if (**format == '-')
			arg->right_pad = 1;
		else if (**format == '+')
			arg->force_sign = 1;
		else if (**format == ' ')
			arg->blank_sign = 1;
		(*format)++;
		if (arg->right_pad)
			arg->pad_zeroes = 0;
		return (pf_parse_flags(format, arg));
	}
	else
		return (*format);
}
