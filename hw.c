/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hw.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 22:20:15 by wclayton          #+#    #+#             */
/*   Updated: 2018/12/25 23:16:26 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void hw(void)
{
	int i;
	int j;
	int k;

	i = -1;
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
						if (j >= g_glob[i].height)
							g_glob[i].height = j + 1;
						if (k >= g_glob[i].width)
							g_glob[i].width = k + 1;
					}
				}
			}
		}
	}
}
