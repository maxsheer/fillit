/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 22:04:19 by dgrady            #+#    #+#             */
/*   Updated: 2018/12/25 23:24:07 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

void	print_solution(char **map, short size)
{
	int i;
	int j;
	
	i = -1;
	while(++i < size)
	{
		j = -1;
		while(++j < size)
			printf("%c", map[i][j]);
		printf ("\n");
	}
}

char	**create_map()
{
	char	**map;
	int i;
	
	map = (char**)malloc(sizeof(char*) * 18);
	while(i < 18)
		map[i] = ft_strnew(18);
	return (map);
}

int		find_size(short cell_count)
{
	int kek;
	int size;
	size = 1;

	kek = cell_count + 1;
	while (size * size < kek * 4)
				size++;
	return (size);
}
