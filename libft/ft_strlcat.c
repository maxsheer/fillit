/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:45:00 by wclayton          #+#    #+#             */
/*   Updated: 2018/11/26 05:58:47 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t d;
	size_t s;

	d = 0;
	s = ft_strlen(src);
	while (dst[d] != '\0' && d < size)
		d++;
	if (d == size)
		return (size + s);
	if (s >= size - d - 1)
	{
		ft_memcpy(&dst[d], src, size - d - 1);
		dst[size - 1] = '\0';
	}
	else
	{
		ft_memcpy(&dst[d], src, s);
		dst[d + s] = '\0';
	}
	return (d + s);
}
