/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:59:09 by mbeuil            #+#    #+#             */
/*   Updated: 2018/01/02 15:42:04 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <stdint.h>
# include <inttypes.h>
# include <wchar.h>

# define INTMIN		-2147483648
# define INTMAX		2147483647
# define UINTMAX	4294967295
# define LONGMIN	-9223372036854775808
# define LONGMAX	9223372036854775807
# define ULONGMAX	18446744073709551615

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
long				ft_atol(const char *str);
long long			ft_atoll(const char *str);
void				ft_bzero(void *s, size_t n);
double				ft_ceil(double x);
double				ft_floor(double x);
double				ft_fmod(double x, double y);
long double			ft_fmodl(long double x, long double y);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isinf(double x);
int					ft_isinfl(long double x);
int					ft_isint(char *str);
int					ft_islower(int c);
int					ft_isnan(double x);
int					ft_isnanl(long double x);
int					ft_isnumber(char *str);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
char				*ft_itoa(int n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddback(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstfree(void *content, size_t content_size);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
size_t				ft_lstlen(t_list *lst);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstprint(t_list *lst);
void				ft_lstprint_fd(t_list *lst, int fd);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnstr(char const *s, size_t n);
void				ft_putnstr_fd(char const *s, size_t n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putwchar(wchar_t wc);
void				ft_putwchar_fd(wchar_t wc, int fd);
void				ft_putwstr(wchar_t const *ws);
void				ft_putwstr_fd(wchar_t const *ws, int fd);
void				*ft_realloc(void *ptr, size_t size);
double				ft_round(double x);
void				ft_strarrayfree(char **arr);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strndup(const char *s1, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
size_t				ft_strnlen(const char *s, size_t maxlen);
char				*ft_strnstr(const char *haystack, const char *needle,
	size_t len);
char				*ft_strpbrk(const char *s, const char *charset);
char				*ft_strrchr(const char *s, int c);
char				*ft_strsep(char **stringp, const char *delim);
char				**ft_strsplit(char const *s, char c);
size_t				ft_strspn(const char *s, const char *charset);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_utoa_base(unsigned long long n, int base);
wchar_t				*ft_wcscpy(wchar_t *s1, const wchar_t *s2);
wchar_t				*ft_wcsdup(const wchar_t *s);
size_t				ft_wcslen(const wchar_t *s);
wchar_t				*ft_wcsncpy(wchar_t *s1, const wchar_t *s2, size_t len);
wchar_t				*ft_wcsndup(const wchar_t *s1, size_t n);
size_t				ft_wcsnlen(const wchar_t *s, size_t maxlen);

#endif
