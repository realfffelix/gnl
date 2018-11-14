/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdubois <fdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:08:27 by fdubois           #+#    #+#             */
/*   Updated: 2018/11/06 17:35:24 by fdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t		len;
	size_t		n;
	char const	*d;
	char const	*s;

	n = size;
	d = dest;
	s = src;
	while (n-- != 0 && *dest != '\0')
		dest++;
	len = dest - d;
	n = size - len;
	if (n-- == 0)
		return (len + ft_strlen(src));
	while (*src != '\0')
	{
		if (n != 0)
		{
			*dest++ = *src;
			n--;
		}
		src++;
	}
	*dest = '\0';
	return (len + (src - s));
}
