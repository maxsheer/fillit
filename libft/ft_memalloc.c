/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 00:59:48 by wclayton          #+#    #+#             */
/*   Updated: 2018/11/25 06:17:28 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*rslt;
	size_t	s;

	s = 0;
	rslt = (void*)malloc(sizeof(void) * size);
	if (rslt == NULL)
		return (NULL);
	while (s < size)
	{
		((unsigned char*)rslt)[s] = 0;
		s++;
	}
	return (rslt);
}
