/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:51:47 by mbeuil            #+#    #+#             */
/*   Updated: 2018/04/11 13:51:49 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

static int		free_fd(const int fd, t_list **list)
{
	t_list			*curr;
	t_list			*prev;

	curr = *list;
	prev = NULL;
	while ((int)curr->content_size != fd)
	{
		prev = curr;
		curr = curr->next;
	}
	if (prev)
		prev->next = curr->next;
	else
		*list = curr->next;
	free(curr->content);
	free(curr);
	return (0);
}

static int		next_line(char **line, t_list *list, char *chr)
{
	char			*tmp;
	size_t			len;

	if (!chr)
	{
		if (!(*line = ft_strdup(list->content)))
			return (-1);
		if (!(tmp = ft_strdup(list->content + ft_strlen(list->content))))
			return (-1);
	}
	else
	{
		len = ft_strlen(list->content) - ft_strlen(chr);
		if (!(*line = ft_strndup(list->content, len)))
			return (-1);
		if (!(tmp = ft_strdup(chr + 1)))
			return (-1);
	}
	free(list->content);
	list->content = tmp;
	return (1);
}

static int		read_fd(const int fd, t_list *list)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if (ft_strequ(buf, "\0"))
			return (-1);
		if (!(list->content = ft_realloc(list->content,
			ft_strlen(list->content) + ft_strlen(buf) + 1)))
			return (-1);
		ft_strcat(list->content, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ret);
}

static t_list	*init_fd(const int fd, t_list **list)
{
	t_list			*tmp;

	tmp = *list;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = ft_lstnew(NULL, 0)))
		return (NULL);
	tmp->content_size = fd;
	if (!(tmp->content = ft_strnew(1)))
		return (NULL);
	ft_lstadd(list, tmp);
	return (*list);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	char			*chr;
	t_list			*list_fd;
	static t_list	*list;

	if (fd < 0 || BUFF_SIZE <= 0 || line == NULL
		|| !(list_fd = init_fd(fd, &list)))
		return (-1);
	if (list_fd->content && (chr = ft_strchr(list_fd->content, '\n')))
		return (next_line(line, list_fd, chr));
	if ((ret = read_fd(fd, list_fd)) == -1)
		return (-1);
	if (list_fd->content && ft_strlen(list_fd->content) != 0)
	{
		chr = ft_strchr(list_fd->content, '\n');
		return (next_line(line, list_fd, chr));
	}
	return (free_fd(fd, &list));
}
