/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 22:04:19 by dgrady            #+#    #+#             */
/*   Updated: 2019/01/09 20:10:43 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_solution(char **map, short size)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (map[i][j] == 0)
				ft_putchar('.');
			else
				ft_putchar(map[i][j]);
		}
		ft_putchar('\n');
	}
}

char	**create_map(void)
{
	char	**map;
	int		i;

	i = -1;
	Z((map = (char**)malloc(sizeof(char*) * 18)));
	while (++i < 18)
		Z((map[i] = ft_strnew(18)));
	return (map);
}

int		find_size(short g_cell_count)
{
	int kek;
	int size;

	size = 1;
	kek = g_cell_count + 1;
	while (size * size < kek * 4)
		size++;
	return (size);
}
