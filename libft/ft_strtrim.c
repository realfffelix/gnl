/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:18:30 by fdubois           #+#    #+#             */
/*   Updated: 2018/11/07 19:10:10 by fdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_douille(char const *s)
{
	int		i;
	size_t	start;
	size_t	end;
	char	*str;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
		return ((str = ft_strdup(s + i)) ? str : NULL);
	start = i;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			end = i++;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	i = -1;
	while ((++i + start) <= end)
		str[i] = s[start + i];
	str[i] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	if (s == NULL)
		return (NULL);
	return (ft_douille(s));
}
