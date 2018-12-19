/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 20:41:03 by wclayton          #+#    #+#             */
/*   Updated: 2018/12/19 22:17:15 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int fd;

	if (argc != 2 || ((fd = open(argv[1], O_RDONLY)) < 0))
		return (usage());
	if (!validate(fd) || !cut())
	{
		write(2, "error\n", 6);
		return (0);
	}

	return (0);
}
