/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:30:40 by wclayton          #+#    #+#             */
/*   Updated: 2018/11/26 01:13:09 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char			*rslt;
	unsigned int	i;

	i = 0;
	rslt = (char*)malloc(sizeof(char) * (len + 1));
	if (rslt == NULL || s == NULL)
		return (NULL);
	rslt[len] = '\0';
	while (i < len)
	{
		rslt[i] = s[start + i];
		i++;
	}
	return (rslt);
}
