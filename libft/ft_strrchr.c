/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:41:01 by wclayton          #+#    #+#             */
/*   Updated: 2018/11/25 05:31:28 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int i;

	i = ft_strlen(str);
	if (str != NULL)
	{
		if ((unsigned char)c == '\0')
			return (&((char*)str)[i]);
		while (i > 0)
		{
			if ((unsigned char)c == str[i - 1])
				return (&((char*)str)[i - 1]);
			i--;
		}
	}
	return (NULL);
}
