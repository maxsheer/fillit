/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 02:00:28 by wclayton          #+#    #+#             */
/*   Updated: 2018/11/26 01:09:26 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *to_find, const char *str, size_t n)
{
	unsigned int	k;
	unsigned int	f;
	size_t			i;

	f = 0;
	i = 0;
	if (*str == '\0')
		return ((char*)to_find);
	while (to_find[i] != '\0' && i < n)
	{
		k = -1;
		f = 1;
		while (str[++k] != '\0' && i + k < n + 1)
			if (str[k] != to_find[i + k])
				f = 0;
		if (f == 1 && !(i + k - 1 >= n))
			return (&((char*)to_find)[i]);
		i++;
	}
	if (f == 0)
		return (0);
	return (0);
}
