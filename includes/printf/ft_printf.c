/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 22:26:48 by mbeuil            #+#    #+#             */
/*   Updated: 2017/12/04 11:33:57 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../libft/libft.h"

static int	handle_arg(const char **format, va_list *args, t_arg *sarg)
{
	size_t	ret;

	(*format)++;
	while (ft_check_option(format))
	{
		if ((*(*format)) == '\0')
			return (0);
		if ((pf_parse_flags(format, sarg)) == NULL)
			return (-1);
		if ((pf_parse_width(format, sarg)) == NULL)
			return (-1);
		if ((pf_parse_precision(format, sarg)) == NULL)
			return (-1);
		if ((pf_parse_length(format, sarg)) == NULL)
			return (-1);
	}
	if (**format == '\0')
		return (0);
	else
		ret = ft_get_conv(**format, format, args, sarg);
	(*format)++;
	return (ret);
}

static int	ft_read_format(const char *format, va_list *args, size_t chrs)
{
	char	*splitter;
	t_arg	sarg;
	size_t	handler_len;

	splitter = ft_strchr(format, '%');
	if (*format == '\0')
		return (chrs);
	if (splitter == NULL)
	{
		ft_putstr(format);
		return (chrs + ft_strlen(format));
	}
	else if (splitter > format)
	{
		ft_putnstr(format, splitter - format);
		return (ft_read_format(splitter, args, chrs + (splitter - format)));
	}
	else
	{
		ft_bzero(&sarg, sizeof(sarg));
		if ((handler_len = handle_arg(&format, args, &sarg)) == -1)
			return (-1);
		else
			return (ft_read_format(format, args, chrs + handler_len));
	}
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_read_format(format, &ap, 0);
	va_end(ap);
	return (ret);
}
