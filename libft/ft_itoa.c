/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdubois <fdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 17:04:46 by fdubois           #+#    #+#             */
/*   Updated: 2018/11/06 16:50:58 by fdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits(int n)
{
	int i;

	i = 2;
	if (n == -2147483648)
		return (12);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char				*str;
	unsigned long long	nb;
	int					len;

	len = digits(n);
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	if (n == -2147483648)
	{
		ft_strncpy(str, "-2147483648", 11);
		return (str);
	}
	nb = (n < 0) ? (long long)(n * -1) : n;
	if (nb == 0)
		str[--len] = '0';
	while (nb != 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		str[--len] = '-';
	return (str);
}
