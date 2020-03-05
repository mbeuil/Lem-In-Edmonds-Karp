#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 02:56:07 by mbeuil            #+#    #+#              #
#    Updated: 2018/01/08 02:56:09 by mbeuil           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libftgnlprintf.a

CC			=	gcc

RM			=	/bin/rm -f

CFLAGS		=	-Wall -Wextra -Werror

DIR_LFT		=	./libft

DIR_GNL		=	./gnl

DIR_PRINTF	=	./printf



SRCS_LFT	=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
				ft_memmove.c ft_memchr.c ft_strlen.c ft_strcpy.c \
				ft_strdup.c ft_memcmp.c ft_strchr.c ft_strrchr.c \
				ft_strncpy.c ft_strcat.c ft_strncat.c ft_strstr.c \
				ft_strlcat.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
				ft_atoi.c ft_isalpha.c ft_islower.c ft_isupper.c \
				ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
				ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
				ft_strnew.c ft_strdel.c ft_strclr.c ft_putchar.c \
				ft_striter.c ft_putstr.c ft_striteri.c ft_strmap.c \
				ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
				ft_strjoin.c ft_strtrim.c ft_isspace.c ft_strndup.c \
				ft_strpbrk.c ft_strsep.c ft_strsplit.c ft_itoa.c \
				ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c \
				ft_lstadd.c ft_lstdel.c ft_lstiter.c ft_lstmap.c ft_strnlen.c \
				ft_strspn.c ft_realloc.c ft_putnstr_fd.c ft_putnstr.c \
				ft_utoa_base.c ft_putwchar.c ft_putwchar_fd.c \
				ft_putwstr.c ft_putwstr_fd.c ft_putnbrbase.c \
				ft_wcslen.c ft_wcsnlen.c ft_wcscpy.c ft_wcsdup.c \
				ft_wcsncpy.c ft_wcsndup.c ft_isnan.c ft_isinf.c \
				ft_round.c ft_floor.c ft_ceil.c ft_isnanl.c ft_isinfl.c \
				ft_fmod.c ft_fmodl.c ft_lstprint.c ft_lstprint_fd.c \
				ft_lstaddback.c ft_lstfree.c ft_atol.c ft_atoll.c \
				ft_lstlen.c ft_strarrayfree.c ft_isnumber.c ft_isint.c \
				ft_ispunct.c

SRCS_GNL	=	get_next_line.c

SRCS_PRINTF	=	ft_printf.c pf_calc_nbrstrlen.c \
				pf_check_option.c pf_get_conv.c \
				pf_get_unsigned_from_length.c pf_handle_char.c \
				pf_handle_escape.c pf_handle_hex.c pf_handle_int.c \
				pf_handle_longd.c pf_handle_longo.c pf_handle_longu.c \
				pf_handle_null.c pf_handle_octal.c pf_handle_ptr.c \
				pf_handle_str.c pf_handle_uint.c pf_handle_uinto.c \
				pf_handle_uintx.c pf_handle_unsigned.c \
				pf_handle_wchar.c pf_handle_wstr.c pf_max.c \
				pf_nbr_prefix.c pf_nbrlen.c pf_nstrlen.c \
				pf_parse_flags.c pf_parse_length.c pf_parse_precision.c \
				pf_parse_width.c pf_putnbrbp.c pf_width_pad.c



OBJS_LFT	=	$(addprefix $(DIR_LFT)/, ${SRCS_LFT:.c=.o})

OBJS_GNL	=	$(addprefix $(DIR_GNL)/, ${SRCS_GNL:.c=.o})

OBJS_PRINTF	=	$(addprefix $(DIR_PRINTF)/, ${SRCS_PRINTF:.c=.o})



all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS_LFT) $(OBJS_GNL) $(OBJS_PRINTF)
	@ar rc $(NAME) $^
	@ranlib $(NAME)

clean:
	@$(RM) $(OBJS_LFT) $(OBJS_GNL) $(OBJS_PRINTF)

fclean:	clean
	@$(RM) $(NAME)

re: fclean all

norme:
	@norminette $(addprefix $(DIR_LFT)/, $(SRCS_LFT)) $(addprefix $(DIR_GNL)/, $(SRCS_GNL)) \
	$(addprefix $(DIR_PRINTF)/, $(SRCS_PRINTF))

.PHONY: all, clean, fclean, re
