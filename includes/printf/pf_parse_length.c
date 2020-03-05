/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 22:26:48 by mbeuil            #+#    #+#             */
/*   Updated: 2017/12/04 11:33:57 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../libft/libft.h"

static const char	*sub_parse_length(const char **format, t_arg *arg)
{
	if (**format == 'h' && (!arg->length || arg->length == hh))
		arg->length = h;
	else if (**format == 'l' && (!arg->length || arg->length == hh))
		arg->length = l;
	else if (**format == 'j' && (!arg->length || arg->length == hh))
		arg->length = j;
	else if (**format == 'z' && (!arg->length || arg->length == hh))
		arg->length = z;
	return ((*format)++);
}

const char			*pf_parse_length(const char **format, t_arg *arg)
{
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		if (!arg->length || arg->length == hh)
			arg->length = hh;
		return (*format += 2);
	}
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		if (!arg->length || arg->length == hh)
			arg->length = ll;
		return (*format += 2);
	}
	else if (**format == 'h' || **format == 'l' || **format == 'j' ||
					**format == 'z')
	{
		sub_parse_length(format, arg);
		return (*format);
	}
	else
		return (*format);
}
