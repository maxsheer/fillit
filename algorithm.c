/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 20:46:51 by dgrady            #+#    #+#             */
/*   Updated: 2018/12/26 21:53:40 by dgrady           ###   ########.fr       */
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
			if (tetr.X + j >= size || tetr.Y + i >= size)
				return (0);
			if (tetr.store[i][j] == 1)
				if(map[tetr.Y + i][tetr.X + j] != 0)
					return (0);
		}
	}
	return 1;
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
				map[tetr.Y + i][tetr.X + j] = tetr.letter;
	}
}

void	clear(t_huyna	tetr, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < tetr.height)
	{
		j = -1;
		while (++j < tetr.width)
			if (map[tetr.Y + i][tetr.X + j] == tetr.letter)
				map[tetr.Y + i][tetr.X + j] = 0;
	}
}

int		algo(short	size)
{
	int	index;
	char **map;
	
	map = create_map();
	index = 0;
	while (1)
	{
		if (check(g_glob[index], map, size))
		{
			place(g_glob[index], map);
			index++;
			if (index == cell_count + 1)
			{
				print_solution(map, size);
				return (1);
			}
		}
		else
		{
			if (g_glob[index].X < size - g_glob[index].width + 1)
				g_glob[index].X++;
			else if (g_glob[index].Y < size - g_glob[index].height + 1)
			{
				g_glob[index].X = 0;
				g_glob[index].Y++;
			}
			else
			{
				g_glob[index].X = 0;
				g_glob[index].Y = 0;
				index--;
				if (index == -1)
				{
					clear(g_glob[index], map);
					size++;
					index = 0;
					continue ;
				}
				clear(g_glob[index], map);
				g_glob[index].X++; //mb sega 
			}
		}
		if(size == 17)
			return (0);
			
	}
}
