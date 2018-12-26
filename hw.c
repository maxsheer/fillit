/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hw.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 22:20:15 by wclayton          #+#    #+#             */
/*   Updated: 2018/12/27 02:00:29 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int g_i = -1;

void	hw(void)
{
	int j;
	int k;

	while (++g_i < 26)
	{
		if (g_glob[g_i].store)
		{
			j = -1;
			while (++j < 4)
			{
				k = -1;
				while (++k < 4)
				{
					if (g_glob[g_i].store[j][k] == 1)
					{
						if (j >= g_glob[g_i].height)
							g_glob[g_i].height = j + 1;
						if (k >= g_glob[g_i].width)
							g_glob[g_i].width = k + 1;
					}
				}
			}
		}
	}
}
