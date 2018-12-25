/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hw.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 22:20:15 by wclayton          #+#    #+#             */
/*   Updated: 2018/12/25 22:47:34 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void hw(void)
{
	int i;
	int j;
	int k;
	int maxw;
	int maxh;

	i = -1;
	maxw = 0;
	maxh = 0;
	while (++i < 26)
	{
		if (g_glob[i].store)
		{
			j = -1;
			while (++j < 4)
			{
				k = -1;
				while (++k < 4)
				{
					if (g_glob[i].store[j][k] == 1)
					{
						if (j > maxh)
							maxh = j;
						if (k > maxw)
							maxw = k;
					}
				}
			}
		}
	}
}
