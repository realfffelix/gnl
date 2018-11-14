/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdubois <fdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 00:44:15 by fdubois           #+#    #+#             */
/*   Updated: 2018/11/13 16:14:02 by fdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*mem;

	i = 0;
	if (!(mem = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	while (i < size)
	{
		mem[i] = '\0';
		i++;
	}
	return (mem);
}
