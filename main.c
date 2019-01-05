/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 20:41:03 by wclayton          #+#    #+#             */
/*   Updated: 2019/01/05 22:54:20 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	**map;

	if (argc != 2 || ((fd = open(argv[1], O_RDONLY)) < 0))
		return (usage());
	if (!validate(fd, 0))
	{
		write(2, "error\n", 6);
		return (0);
	}
	cut();
	hw();
	map = create_map();
	algo(find_size(g_cell_count), map, 0);
	return (0);
}
