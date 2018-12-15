/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 21:11:28 by wclayton          #+#    #+#             */
/*   Updated: 2018/12/15 23:55:11 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
int vallinks(t_uc *st)
{
	printf("init\n");
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
	printf("%d %d\n", sc, lc);
	if (sc != 4 || lc < 6)
		return (0);
	return (1);
}

int	validate(int fd)
{
	printf("valinit\n");
	size_t i;
	short cell_count;
	char *nl;
	t_uc st[36];
	size_t j;

	i = -1;
	while(++i < 36)
		st[i] = 0;
	cell_count = -1;
	while (++cell_count < 26)
	{
		printf("iter\n");
		i = -1;
		while (++i < 4)
		{
			if (!get_next_line(fd, &nl) || ft_strlen(nl) != 4)
			{
				printf("NL %zu %s\n", ft_strlen(nl), nl);
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
		j = -1;
		while (++j < 36)
			printf("%d", st[j]);
		printf("\nst\n");
		if (get_next_line(fd, &nl) > 0)
		{
			get_next_line(fd, &nl);
			printf("mtz\n");
			printf("a cho tut u nas %d %s\n", ft_strlen(nl), nl);
			if (ft_strlen(nl) != 0 || !vallinks(st))
			{
				write(2, "hierror\n", 8);
				exit(0);
			}
		}
		else
		{
			printf("letz\n");
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
