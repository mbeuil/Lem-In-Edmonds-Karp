/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_check_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:08:28 by mbeuil            #+#    #+#             */
/*   Updated: 2018/10/31 15:08:36 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../libft/libft.h"

int	ft_check_option(const char **format)
{
	int	i;

	i = 0;
	if (**format == '#' || **format == '0' || **format == '-' || **format == '+'
		|| **format == ' ' || ft_isdigit(**format) || **format == '.'
		|| **format == 'h' || **format == 'l' || **format == 'j'
		|| **format == 'z')
		i = 1;
	return (i);
}
