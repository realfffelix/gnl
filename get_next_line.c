/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:14:45 by fdubois           #+#    #+#             */
/*   Updated: 2018/11/14 17:54:14 by fdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include "./libft/libft.h"

static size_t ft_strclen(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static t_fdl	*ft_fdlnew(t_fdl **head, char *str, int fd)
{
	t_fdl	*new;

	if(!(new = (t_fdl*)malloc(sizeof(t_fdl))))
		return (NULL);
	if(!(new->str = ft_strdup(str)))
		return (NULL);
	new->fd = fd;
	new->offset = 0;
	new->next = *head;
	*head = new;
	return (new);
}

static void	ft_fdldel(t_fdl **head, int fd)
{
	t_fdl	*ptr;
	t_fdl	*prev;

	ptr = *head;
	prev = NULL;

	while (ptr->next != NULL && (int)ptr->fd != fd)
	{
		prev = ptr;
		ptr = ptr->next;
	}

	if ((int)ptr->fd == fd)
	{
		if (prev != NULL)
			prev->next = ptr->next;
		ft_strdel(&(ptr->str));
		if (ptr == *head)
		{
			*head = ptr->next;
		}
		free((void**)ptr);
	}
}

static char	*get_prepend(t_fdl **head, int fd)
{
	t_fdl	*ptr;
	char	*prepend;

	ptr = *head;

	while (ptr != NULL && ptr->fd != fd)
		ptr = ptr->next;

	if (ptr != NULL && ptr->fd == fd)
	{
//			printf("\n |1:  %s, %zu |\n", ptr->str, ptr->offset);

		if (ft_strchr((ptr->str + ptr->offset), '\n'))
		{
			if (!(prepend = ft_strsub(ptr->str, ptr->offset, ft_strclen((ptr->str + ptr->offset), '\n'))))
				return (NULL);
	//		printf("\n |1:  %s, %zu |\n", (ptr->str + ptr->offset), ptr->offset);
			ptr->offset += ft_strclen((ptr->str + ptr->offset), '\n') + 1;
	//		printf("\n |2:  %s, %zu |\n", (ptr->str + ptr->offset), ptr->offset);
			return (prepend);
		}
		else
		{
			if (!(prepend = ft_strsub(ptr->str, ptr->offset, ft_strclen((ptr->str + ptr->offset), '\0'))))
				return (NULL);
		//	printf("\n |1:  %s, %zu |\n", (ptr->str + ptr->offset), ptr->offset);
			ptr->offset += ft_strclen((ptr->str + ptr->offset), '\n') + 1;
		//	printf("\n |2:  %s, %zu |\n", (ptr->str + ptr->offset), ptr->offset);
			ft_fdldel(head, fd);
			return (prepend);
		}
	}
	return (NULL);
}

int	get_next_line(const int fd, char **line)
{
	char	buffer[BUFF_SIZE + 1];
	static t_fdl	*list;
	t_fdl	*ptr;
	int readval;
	char	*prepend;

	if (!(*line = ft_strnew(1)))
		return (-1);
	prepend = get_prepend(&list, fd);
	if (prepend != NULL)
	{
		if (!(*line = ft_strjoinfr(*line, prepend)))
			return (-1);
		free(prepend);
		ptr = list;
		while (ptr != NULL)
		{
			if ((int)ptr->fd == fd)
				return (1);
			ptr = ptr->next;
		}
	}
	if (fd < 0 || (readval = read(fd, &buffer, BUFF_SIZE)) < 0 || line == NULL)
		return (-1);
	while (readval > 0)
	{
		if (ft_strchr(buffer, '\n') == NULL)
		{
			buffer[readval] = '\0';
			if (!(*line = ft_strjoinfr(*line, buffer)))
				return (-1);
			//		readval = read(fd, &buffer, BUFF_SIZE);
		}
		if (ft_strchr(buffer, '\n'))
		{
			buffer[readval] = '\0';
			*(ft_strchr(buffer, '\n')) = '\0';
			if (!(*line = ft_strjoinfr(*line, buffer)))
				return (-1);
			*(ft_strchr(buffer, '\0')) = '\n';
			if (!(ptr = ft_fdlnew(&list, (ft_strchr(buffer, '\n') + 1), fd)))
				return (-1);
			return (1);
		}
		readval = read(fd, &buffer, BUFF_SIZE);
	}
	return (readval == -1 ? -1 : 0);
}
