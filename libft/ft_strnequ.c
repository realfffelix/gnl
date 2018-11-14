/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdubois <fdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 17:49:20 by fdubois           #+#    #+#             */
/*   Updated: 2018/11/07 15:56:55 by fdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while ((i < (n - 1)) && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s2[i] != s1[i])
			return (0);
		i++;
	}
	if (s1[i] == s2[i] || (n == 0))
		return (1);
	else
		return (0);
}
