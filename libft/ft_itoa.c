/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 01:09:14 by wclayton          #+#    #+#             */
/*   Updated: 2018/11/25 01:14:48 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chs(unsigned int t)
{
	int size;

	if (t == 0)
		return (1);
	size = 0;
	while (t > 0)
	{
		t /= 10;
		size++;
	}
	return (size);
}

static void	ft_fill(char **rslt, int iter, int m, unsigned int tmp)
{
	int i;

	i = 1;
	if (tmp >= 10)
		ft_fill(rslt, iter - 1, m, tmp / 10);
	(*rslt)[iter + m - 1] = '0' + tmp % 10;
}

char		*ft_itoa(int n)
{
	int				size;
	unsigned int	tmp;
	int				m;
	char			*rslt;

	m = 0;
	if (n < 0)
	{
		m = 1;
		tmp = -n;
	}
	else
		tmp = n;
	size = ft_chs(tmp);
	rslt = (char*)malloc(sizeof(char) * (size + m + 1));
	if (rslt == NULL)
		return (NULL);
	if (m == 1)
		rslt[0] = '-';
	rslt[size + m] = '\0';
	ft_fill(&rslt, size, m, tmp);
	return (rslt);
}
