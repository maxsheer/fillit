/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 03:58:07 by wclayton          #+#    #+#             */
/*   Updated: 2018/11/26 04:49:29 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	tmp = new;
	while (tmp && lst->next)
	{
		tmp->next = f(lst->next);
		if (!(tmp->next))
		{
			free(tmp->next);
			return (NULL);
		}
		lst = lst->next;
		tmp = tmp->next;
	}
	return (new);
}
