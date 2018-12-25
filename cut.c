/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 20:42:04 by wclayton          #+#    #+#             */
/*   Updated: 2018/12/25 23:15:53 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
int	rfour(int i)
{
	int j;

	j = -1;
	while(++j < 4)
	{
		if (g_glob[i].store[j][0] == 1)
			return (0);
	}
	j = -1;
	while(++j < 16)
	{
		if (j % 4 < 3)
		{
			g_glob[i].store[j / 4][j % 4] = g_glob[i].store[j / 4][j % 4 + 1];
			g_glob[i].store[j / 4][j % 4 + 1] = 0;
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
		if (g_glob[i].store[0][j] == 1)
			return (0);
	}
	j = -1;
	while (++j < 12)
	{
		g_glob[i].store[j / 4][j % 4] = g_glob[i].store[j / 4 + 1][j % 4];
		g_glob[i].store[j / 4 + 1][j % 4] = 0;
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
			while(rfour(i) > 0)
				;
			while(cfour(i) > 0)
				;
		}
	}
}
