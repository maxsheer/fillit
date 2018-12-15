/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 07:14:02 by wclayton          #+#    #+#             */
/*   Updated: 2018/11/26 04:51:58 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t c;
	size_t i;

	c = 0;
	i = 0;
	while (str[i] != 0)
	{
		c += 1;
		i++;
	}
	return (c);
}
