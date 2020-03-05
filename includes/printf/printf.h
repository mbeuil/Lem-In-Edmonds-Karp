/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 11:02:08 by mbeuil            #+#    #+#             */
/*   Updated: 2018/10/31 11:02:14 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdint.h>
# include <inttypes.h>
# include <wchar.h>

typedef struct		s_arg
{
	int				force_prefix : 1;
	int				pad_zeroes : 1;
	int				right_pad : 1;
	int				force_sign : 1;
	int				blank_sign : 1;
	int				got_width : 1;
	int				got_precision : 1;
	unsigned int	width;
	unsigned int	precision;
	enum {
		none,
		hh,
		h,
		l,
		ll,
		j,
		z
	}				length;
}					t_arg;

typedef struct		s_convtbl
{
	char			key;
	size_t			(*f)(const char**, va_list*, t_arg*);
}					t_convtbl;

const char			*pf_parse_length(const char **format, t_arg *arg);
const char			*pf_parse_flags(const char **format, t_arg *arg);
const char			*pf_parse_width(const char **format, t_arg *arg);
const char			*pf_parse_precision(const char **format, t_arg *arg);
size_t				ft_get_conv(char c, const char **fromat,
	va_list *args, t_arg *sarg);
size_t				pf_handle_char(const char **format,
	va_list *args, t_arg *arg);
size_t				pf_handle_wchar(const char **format,
	va_list *args, t_arg *arg);
size_t				pf_handle_int(const char **format,
	va_list *args, t_arg *arg);
size_t				pf_handle_longd(const char **format,
	va_list *args, t_arg *arg);
size_t				pf_handle_octal(const char **format,
	va_list *args, t_arg *arg);
size_t				pf_handle_longo(const char **format,
	va_list *args, t_arg *arg);
size_t				pf_handle_longu(const char **format,
	va_list *args, t_arg *arg);
size_t				pf_handle_hex(const char **format,
	va_list *args, t_arg *arg);
size_t				pf_handle_ptr(const char **format,
	va_list *args, t_arg *arg);
size_t				pf_handle_str(const char **format,
	va_list *args, t_arg *arg);
size_t				pf_handle_wstr(const char **format,
	va_list *args, t_arg *arg);
size_t				pf_handle_escape(const char **format,
	va_list *args, t_arg *arg);
size_t				pf_handle_unsigned(const char **format,
	va_list *args, t_arg *arg);
size_t				pf_handle_null(const char **format,
	va_list *args, t_arg *arg);
size_t				ft_nstrlen(const char *str, size_t maxlen);
size_t				ft_printf_nbrforceprefix(uintmax_t nbr,
	char *base, t_arg *arg, char *prefix);
size_t				pf_handle_uint(uintmax_t nbr, t_arg *arg,
	char *base, char *prefix);
size_t				pf_handle_uinto(uintmax_t nbr, t_arg *arg,
	char *base, char *prefix);
size_t				pf_handle_uintx(uintmax_t nbr, t_arg *arg,
	char *base, char *prefix);
int					ft_printf(const char *format, ...);
int					ft_max(int x, int y);
int					ft_check_option(const char **format);
unsigned int		ft_printf_calc_nbrstrlen(uintmax_t nbr,
	char *base, char *p, t_arg *arg);
unsigned int		ft_printf_nbrlen(uintmax_t nbr, char *base);
uintmax_t			ft_printf_get_unsigned_from_length(va_list *args,
	t_arg *arg);
void				ft_putwchar(wchar_t chr);
void				ft_putnbrbase(uintmax_t nbr, char *base);
void				ft_printf_width_pad(int nbrstrlen, int width, char padwith);
void				ft_putnbrbp(uintmax_t nbr, char *base,
	t_arg *arg, unsigned nbr_len);

#endif
