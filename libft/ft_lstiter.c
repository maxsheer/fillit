/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 03:48:20 by wclayton          #+#    #+#             */
/*   Updated: 2018/11/26 03:54:20 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *tmp1;
	t_list *tmp2;

	if (!lst || !f)
		return ;
	tmp1 = lst->next;
	while (tmp1)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		f(tmp2);
	}
	f(lst);
}
