/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:44:54 by mbeuil            #+#    #+#             */
/*   Updated: 2018/04/11 13:44:56 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
** For char 65536 to 1114111 (from 0x10000 to 0x10FFFF in hexa).
** We shift to the right the bit pattern by 18, add 0xF0
** (11110000) and write it. We shift to the right the
** bit pattern by 12, do a bitwise AND operator
** with 0x3F (111111), add 0x80 (10000000) and write it.
** We shift to the right the bit pattern by 6, do a bitwise
** AND operator with 0x3F (111111), add 0x80 (10000000)
** and write it. We then do a bitwise AND operator with
** 0x3F (111111), add 0x80 (10000000) and write it.
** Pattern: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
*/

static void			four_octets(wchar_t wc, int fd)
{
	unsigned char	octet;

	octet = (wc >> 18) | 0xF0;
	write(fd, &octet, 1);
	octet = ((wc >> 12) & 0x3F) | 0x80;
	write(fd, &octet, 1);
	octet = ((wc >> 6) & 0x3F) | 0x80;
	write(fd, &octet, 1);
	octet = (wc & 0x3F) | 0x80;
	write(fd, &octet, 1);
}

/*
** For char 2048 to 65535 (from 0x800 to 0xFFFF in hexa).
** We shift to the right the bit pattern by 12, add 0xC0
** (11100000) and write it. We shift to the right the
** bit pattern by 6, do a bitwise AND operator
** with 0x3F (111111), add 0x80 (10000000) and write it.
** We then do a bitwise AND operator with 0x3F (111111),
** add 0x80 (10000000) and write it.
** Pattern: 1110xxxx 10xxxxxx 10xxxxxx
*/

static void			three_octets(wchar_t wc, int fd)
{
	unsigned char	octet;

	octet = (wc >> 12) | 0xE0;
	write(fd, &octet, 1);
	octet = ((wc >> 6) & 0x3F) | 0x80;
	write(fd, &octet, 1);
	octet = (wc & 0x3F) | 0x80;
	write(fd, &octet, 1);
}

/*
** For char 128 to 2047 (from 0x80 to 0x7FF in hexa).
** We shift to the right the bit pattern by 6, add 0xC0
** (11000000) and write it. We then do a bitwise AND operator
** with 0x3F (111111), add 0x80 (10000000) and write it.
** Pattern: 110xxxxx 10xxxxxx
*/

static void			two_octets(wchar_t wc, int fd)
{
	unsigned char	octet;

	octet = (wc >> 6) | 0xC0;
	write(fd, &octet, 1);
	octet = (wc & 0x3F) | 0x80;
	write(fd, &octet, 1);
}

/*
** For the 127 first characters (from 0x00 to 0x7F in hexa)
** we write the char. For 2, 3 and 4 bytes encoding, we
** need further algorithms.
** Pattern: 0xxxxxxx
*/

void				ft_putwchar_fd(wchar_t wc, int fd)
{
	if (wc <= 0x7F)
		write(fd, &wc, 1);
	else if (wc <= 0x7FF)
		two_octets(wc, fd);
	else if (wc <= 0xFFFF)
		three_octets(wc, fd);
	else if (wc <= 0x10FFFF)
		four_octets(wc, fd);
}
