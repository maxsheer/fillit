/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 02:00:28 by wclayton          #+#    #+#             */
/*   Updated: 2018/11/25 00:22:42 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *to_find, const char *str)
{
	int k;
	int f;

	f = 0;
	k = 0;
	if (*str == '\0')
		return ((char*)to_find);
	while (*to_find != '\0')
	{
		k = 0;
		f = 1;
		while (str[k] != '\0')
		{
			if (str[k] != *(to_find + k))
				f = 0;
			k++;
		}
		if (f == 1)
			return ((char*)to_find);
		to_find++;
	}
	if (f == 0)
		return (0);
	return (0);
}
