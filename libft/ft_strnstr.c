/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdubois <fdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 23:31:46 by fdubois           #+#    #+#             */
/*   Updated: 2018/11/06 17:42:08 by fdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *hay, char const *nee, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (hay[i] == '\0')
		return (NULL);
	if (nee[i] == '\0')
		return ((char*)hay);
	while (hay[i] != '\0' && i < len)
	{
		while (hay[i + j] == nee[j] && (i + j < len))
		{
			if (nee[j + 1] == '\0')
				return ((char*)(hay + i));
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
