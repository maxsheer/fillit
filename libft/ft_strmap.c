/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:05:45 by wclayton          #+#    #+#             */
/*   Updated: 2018/11/26 00:57:19 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	int		i;
	int		size;
	char	*rslt;

	if (s && f)
	{
		i = 0;
		size = ft_strlen(s);
		rslt = (char*)malloc(sizeof(char) * (size + 1));
		if (rslt == NULL)
			return (NULL);
		rslt[size] = '\0';
		while (s[i] != '\0')
		{
			rslt[i] = f(s[i]);
			i++;
		}
		return (rslt);
	}
	return (NULL);
}
