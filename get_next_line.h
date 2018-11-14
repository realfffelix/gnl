/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 23:23:49 by fdubois           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:24 by fdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 420 
# define ww write(1, "@", 1);
# define MALLOCHECK(x) if (!x) return (NULL)

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct		s_fdl
{
	char			*str;
	size_t				fd;
	struct s_fdl	*next;
	size_t				offset;
}					t_fdl;

int					get_next_line(const int fd, char **line);

#endif
