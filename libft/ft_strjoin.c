/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 00:53:20 by wclayton          #+#    #+#             */
/*   Updated: 2018/11/26 01:15:24 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*rslt;
	int		f;
	int		s;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	f = ft_strlen(s1);
	s = ft_strlen(s2);
	rslt = (char*)malloc(sizeof(char) * (f + s + 1));
	if (rslt == NULL)
		return (NULL);
	i = 0;
	while (i < f)
	{
		rslt[i] = s1[i];
		i++;
	}
	while (i < f + s)
	{
		rslt[i] = s2[i - f];
		i++;
	}
	rslt[i] = '\0';
	return (rslt);
}
