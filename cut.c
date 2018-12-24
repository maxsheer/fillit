/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 20:42:04 by wclayton          #+#    #+#             */
/*   Updated: 2018/12/24 23:04:25 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	rfour(int i)
{
	int i;

	j = 1;
	while(++j < 4)
	{
		if (g_glob[i].store[j * 6 + 1] == 1)
			return (0);
	}
	j = 6;
	while(++j < 29)
	{
		if (j % 6 > 0 && j % 6 < 5)
		{
			g_glob[i].store[j] = g_glob[i].store[j + 1];
			g_glob[i].store[j + 1] = 0;
		}
	}
	return (1);
}

int cfour(int i)
{
	int j;

	j = -1;
	while (++j < 4)
	{
		if (g_glob[i].store[6 + j] == 1)
			return (0);
	}
	j = 0;
	while (++j < 5)
	{
		g_glob[i].store[j * 6 + 1] = g_glob[i].store[(j + 1) * 6 + 1];
		g_glob[i].store[(j + 1) * 6 + 1] = 0;
	}
	return (1);
}

void cut(void)
{
	int i;

	i = -1;
	while(++i < 26)
	{
		if (g_glob[i].store)
		{
			while(rfour(i))
				;
			while(cfour(i))
				;
		}
	}
}
