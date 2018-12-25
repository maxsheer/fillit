/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 21:11:28 by wclayton          #+#    #+#             */
/*   Updated: 2018/12/25 23:16:58 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
int vallinks(t_uc *st)
{
	short lc;
	int i;
	short sc;

	i = 6;
	lc = 0;
	sc = 0;
	while (++i < 29)
	{
		if (st[i] == 1)
		{
			sc += st[i];
			lc += st[i - 1] + st[i + 1] + st[i - 6] + st[i + 6];
		}
	}
	if (sc != 4 || lc < 6)
		return (0);
	return (1);
}

int	validate(int fd)
{
	size_t i;
	char *nl;
	t_uc st[36];
	size_t j;

	i = -1;
	while(++i < 36)
		st[i] = 0;
	cell_count = -1;
	g_glob = (t_huyna*)malloc(sizeof(t_huyna) * 28);
	while (++cell_count < 26)
	{
		i = -1;
		while (++i < 4)
		{
			if (!get_next_line(fd, &nl) || ft_strlen(nl) != 4)
			{
				write(2, "hierror\n", 8);
				exit(0);
			}
			j = -1;
			while (++j < 4)
			{
				if (nl[j] == '#')
					st[6 * (i + 1) + 1 + j] = 1;
				else if (nl[j] == '.')
					st[6 * (i + 1) + 1 + j] = 0;
				else
				{
					write(2, "error\n", 6);
					exit(0);
				}
			}
		}
		j = 6;
		i = -1;
		g_glob[cell_count].store = (t_uc**)malloc(sizeof(t_uc*) * 4);
		while(++i < 4)
			g_glob[cell_count].store[i] = (t_uc*)malloc(sizeof(t_uc) * 4);
		while (++i < 16)
			g_glob[cell_count].store[i / 4][i % 4] = 0;
		g_glob[cell_count].letter = cell_count + 'A';
		g_glob[cell_count].X = 0;
		g_glob[cell_count].Y = 0;
		g_glob[cell_count].height = 0;
		g_glob[cell_count].width = 0;
		i = 0;
		while(++j < 29)
		{
			if (j % 6 > 0 && j % 6 < 5)
			{
				g_glob[cell_count].store[i / 4][i % 4] = st[j];
				i++;
			}
		}
		if (get_next_line(fd, &nl) > 0)
		{
			if (ft_strlen(nl) != 0 || !vallinks(st))
			{
				write(2, "error\n", 8);
				exit(0);
			}
		}
		else
		{
			if (!vallinks(st))
			{
				write(2, "error\n", 6);
				exit(0);
			}
			break;
		}
	}
	return (1);
}
