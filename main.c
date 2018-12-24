/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 20:41:03 by wclayton          #+#    #+#             */
/*   Updated: 2018/12/25 00:07:10 by wclayton         ###   ########.fr       */
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
	i = 0;
	cut();
	while (i < 3)
	{
		j = -1;
		while (++j < 16)
		{
			if (j % 4 == 0)
				printf("\n");
			printf("%d", g_glob[i].store[j]);
		}
		printf("\n");
			
		i++;
	}
	return (0);
}
