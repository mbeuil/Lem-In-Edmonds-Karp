/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 22:26:48 by mbeuil            #+#    #+#             */
/*   Updated: 2017/12/04 11:33:57 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../libft/libft.h"

const char	*pf_parse_width(const char **format, t_arg *arg)
{
	if (ft_isdigit(**format))
	{
		arg->got_width = 1;
		arg->width = 0;
		while (ft_isdigit(**format))
			arg->width = arg->width * 10 + (*(*format)++ - '0');
	}
	return (*format);
}
