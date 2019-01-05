/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:27:47 by wclayton          #+#    #+#             */
/*   Updated: 2018/11/25 04:25:28 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	n;
	unsigned int	i;
	char			*rslt;

	n = ft_strlen(s1);
	i = 0;
	rslt = (char*)malloc(sizeof(char) * (n + 1));
	if (rslt == NULL)
		return (NULL);
	while (i < n)
	{
		rslt[i] = s1[i];
		i++;
	}
	rslt[i] = '\0';
	return (rslt);
}
