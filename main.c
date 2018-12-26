/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 20:41:03 by wclayton          #+#    #+#             */
/*   Updated: 2018/12/26 21:43:18 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int fd;
	int i;
	int j;

	if (argc != 2 || ((fd = open(argv[1], O_RDONLY)) < 0))
		return (usage());
	if (!validate(fd))
	{
		write(2, "error\n", 6);
		return (0);
	}
	i = -1;
	cut();
	hw();
	int c = algo(4);
	
	/*
	while (++i < 3)
	{
		j = -1;
		//printf("%d    %d\n", g_glob[i].width, g_glob[i].height);
		while (++j < 16)
		{
			if (j % 4 == 0)
				printf("\n");
			printf("%d", g_glob[i].store[j / 4][j % 4]);
		}
		printf("\n");
		
	}
	*/
	return (0);
}
