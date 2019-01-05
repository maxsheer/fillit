/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:05:45 by wclayton          #+#    #+#             */
/*   Updated: 2018/11/26 00:58:03 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	int		size;
	char	*rslt;

	if (s && f)
	{
		size = ft_strlen(s);
		i = 0;
		rslt = (char*)malloc(sizeof(char) * (size + 1));
		if (rslt == NULL)
			return (NULL);
		rslt[size] = '\0';
		while (s[i] != '\0')
		{
			rslt[i] = f(i, s[i]);
			i++;
		}
		return (rslt);
	}
	return (NULL);
}
