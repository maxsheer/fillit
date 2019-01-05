/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 01:24:35 by wclayton          #+#    #+#             */
/*   Updated: 2018/11/25 04:59:05 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*rslt;
	unsigned int	i;

	rslt = (char*)malloc(sizeof(char) * (size + 1));
	if (rslt == NULL)
		return (NULL);
	i = -1;
	while (++i < size + 1)
		rslt[i] = '\0';
	return (rslt);
}
