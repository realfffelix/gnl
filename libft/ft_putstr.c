/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdubois <fdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 17:06:27 by fdubois           #+#    #+#             */
/*   Updated: 2018/11/07 14:15:05 by fdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	size_t i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			write(1, s + i, 1);
			i++;
		}
	}
}
