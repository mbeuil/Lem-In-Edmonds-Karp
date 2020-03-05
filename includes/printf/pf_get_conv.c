/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 22:26:48 by mbeuil            #+#    #+#             */
/*   Updated: 2017/12/04 11:33:57 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../libft/libft.h"

t_convtbl g_convtbl[] =
{

	{'c', &pf_handle_char},
	{'C', &pf_handle_wchar},
	{'i', &pf_handle_int},
	{'d', &pf_handle_int},
	{'D', &pf_handle_longd},
	{'o', &pf_handle_octal},
	{'O', &pf_handle_longo},
	{'u', &pf_handle_unsigned},
	{'U', &pf_handle_longu},
	{'s', &pf_handle_str},
	{'S', &pf_handle_wstr},
	{'p', &pf_handle_ptr},
	{'x', &pf_handle_hex},
	{'X', &pf_handle_hex},
	{'%', &pf_handle_escape},
	{0, &pf_handle_null}
};

size_t	ft_get_conv(char c, const char **format, va_list *args, t_arg *sarg)
{
	int i;

	i = 0;
	while (g_convtbl[i].key != 0 && g_convtbl[i].key != c)
		i++;
	return (g_convtbl[i].f(format, args, sarg));
}
