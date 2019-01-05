/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 20:46:51 by dgrady            #+#    #+#             */
/*   Updated: 2018/12/27 22:59:39 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int		check(t_huyna tetr, char **map, short size)
{
	int i;
	int j;

	i = -1;
	while (++i < tetr.height)
	{
		j = -1;
		while (++j < tetr.width)
		{
			if (tetr.x + j >= size || tetr.y + i >= size)
				return (0);
			if (tetr.store[i][j] == 1)
				if (map[tetr.y + i][tetr.x + j] != 0)
					return (0);
		}
	}
	return (1);
}

void	place(t_huyna tetr, char **map)
{
	int i;
	int j;

	i = -1;
	while (++i < tetr.height)
	{
		j = -1;
		while (++j < tetr.width)
			if (tetr.store[i][j] == 1)
				map[tetr.y + i][tetr.x + j] = tetr.letter;
	}
}

void	clear(t_huyna tetr, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < tetr.height)
	{
		j = -1;
		while (++j < tetr.width)
			if (map[tetr.y + i][tetr.x + j] == tetr.letter)
				map[tetr.y + i][tetr.x + j] = 0;
	}
}

void	for_norma(char **map, short *index, short *size)
{
	if (g_glob[*index].x < *size - g_glob[*index].width + 1)
		g_glob[*index].x++;
	else if (g_glob[*index].y < *size - g_glob[*index].height + 1)
	{
		g_glob[*index].x = 0;
		g_glob[*index].y++;
	}
	else
	{
		g_glob[*index].x = 0;
		g_glob[*index].y = 0;
		*index = *index - 1;
		if (*index == -1)
		{
			clear(g_glob[0], map);
			*size = *size + 1;
			*index = 0;
			return ;
		}
		clear(g_glob[*index], map);
		g_glob[*index].x++;
	}
}

void	algo(short size, char **map, short index)
{
	while (1)
	{
		if (check(g_glob[index], map, size))
		{
			place(g_glob[index++], map);
			if (index == g_cell_count + 1)
			{
				print_solution(map, size);
				return ;
			}
		}
		else
		{
			if (g_glob[index].x < size - g_glob[index].width + 1)
				g_glob[index].x++;
			else if (g_glob[index].y < size - g_glob[index].height + 1)
			{
				g_glob[index].x = 0;
				g_glob[index].y++;
			}
			else
				for_norma(map, &index, &size);
		}
	}
}
