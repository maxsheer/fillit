/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 02:31:13 by wclayton          #+#    #+#             */
/*   Updated: 2018/11/26 03:30:57 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp2;
	t_list *tmp3;

	if (!alst || !del)
		return ;
	tmp2 = (*alst)->next;
	while (tmp2)
	{
		tmp3 = tmp2;
		tmp2 = tmp2->next;
		ft_lstdelone(&tmp3, del);
	}
	ft_lstdelone(alst, del);
}
