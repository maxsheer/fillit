/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 21:11:28 by wclayton          #+#    #+#             */
/*   Updated: 2018/12/27 03:12:02 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		val(t_uc *st)
{
	short	lc;
	int		i;
	short	sc;

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
	if (sc != 4 || lc < 6)
		return (0);
	return (1);
}

void	globin(void)
{
	int i;

	i = -1;
	g_glob[g_cell_count].store = (t_uc**)malloc(sizeof(t_uc*) * 4);
	while (++i < 4)
		g_glob[g_cell_count].store[i] = (t_uc*)malloc(sizeof(t_uc) * 4);
	i = -1;
	while (++i < 16)
		g_glob[g_cell_count].store[i / 4][i % 4] = 0;
	g_glob[g_cell_count].letter = g_cell_count + 'A';
	g_glob[g_cell_count].x = 0;
	g_glob[g_cell_count].y = 0;
	g_glob[g_cell_count].height = 0;
	g_glob[g_cell_count].width = 0;
}

void	fict1(t_uc *st)
{
	int i;
	int j;

	i = 0;
	j = 16;
	while (++j < 29)
	{
		if (j % 6 > 0 && j % 6 < 5)
		{
			g_glob[g_cell_count].store[i / 4][i % 4] = st[j];
			i++;
		}
	}
}

void	fict2(int fd, char **nl)
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		if (!get_next_line(fd, nl) || ft_strlen(*nl) != 4)
			error();
		j = -1;
		while (++j < 4)
		{
			if ((*nl)[j] == '#')
				st[6 * (i + 1) + 1 + j] = 1;
			else if (nl[j] == '.')
				st[6 * (i + 1) + 1 + j] = 0;
			else
				error();
		}
	}
}

int		validate(int fd)
{
	size_t	i;
	char	*nl;
	t_uc	st[36];
	size_t	j;

	i = -1;
	while (++i < 36)
		st[i] = 0;
	g_cell_count = -1;
	g_glob = (t_huyna*)malloc(sizeof(t_huyna) * 28);
	while (++g_cell_count < 26)
	{
		fict2(fd, &nl);
		globin();
		fict1(st);
		if (get_next_line(fd, &nl) > 0 && (ft_strlen(nl) != 0 || !val(st)))
			error();
		else
		{
			if (!val(st))
				error();
			break ;
		}
	}
	return (1);
}
