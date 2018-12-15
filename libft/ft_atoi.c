/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 11:55:46 by wclayton          #+#    #+#             */
/*   Updated: 2018/11/26 06:32:35 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	long	i;
	int		m;
	long	rez;

	i = 0;
	while ((*str >= 8 && *str <= 13) || *str == 32)
		str++;
	m = ((*str == '-') ? -1 : 1);
	if ((*str == '-') || (*str == '+'))
		str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		rez = i;
		i = i * 10 + (*str - '0');
		if (m > 0 && i < rez)
			return (-1);
		if (m < 0 && i < rez)
			return (0);
		str++;
	}
	return (m * i);
}
