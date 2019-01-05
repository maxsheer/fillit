/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:15:39 by wclayton          #+#    #+#             */
/*   Updated: 2018/11/25 04:24:39 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			t;
	unsigned char	*s;
	unsigned char	*d;

	t = 0;
	s = (unsigned char*)s1;
	d = (unsigned char*)s2;
	while (t < n)
	{
		if (s[t] != d[t])
			return (s[t] - d[t]);
		t++;
	}
	return (0);
}
