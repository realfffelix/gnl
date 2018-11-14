/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fffelix <fdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 00:23:29 by fffelix           #+#    #+#             */
/*   Updated: 2018/10/23 02:16:24 by fdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst != NULL && del != NULL)
	{
		if ((*alst)->next)
		{
			ft_lstdel(&(*alst)->next,
			del);
		}
		ft_lstdelone(alst, del);
	}
}
