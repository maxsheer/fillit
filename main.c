/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 20:41:03 by wclayton          #+#    #+#             */
/*   Updated: 2018/12/18 18:52:59 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int fd;

	if (argc != 2 || ((fd = open(argv[1], O_RDONLY)) < 0))
		return (usage());
	printf("%d\n", validate(fd));
	return (0);
}
