/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 04:26:31 by wclayton          #+#    #+#             */
/*   Updated: 2018/11/25 05:57:48 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	s = (unsigned char*)s1;
	d = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while ((s[i] == d[i]) && (s[i] != '\0') && (i < n - 1))
		i++;
	return (s[i] - d[i]);
}
