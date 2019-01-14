/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 21:11:28 by wclayton          #+#    #+#             */
/*   Updated: 2019/01/09 20:14:04 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		val(void)
{
	short	lc;
	int		i;
	short	sc;

	i = 6;
	lc = 0;
	sc = 0;
	while (++i < 29)
	{
		if (g_st[i] == 1)
		{
			sc += g_st[i];
			lc += g_st[i - 1] + g_st[i + 1] + g_st[i - 6] + g_st[i + 6];
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
	Z((g_glob[g_cell_count].store = (t_uc**)malloc(sizeof(t_uc*) * 4)));
	while (++i < 4)
		Z((g_glob[g_cell_count].store[i] = (t_uc*)malloc(sizeof(t_uc) * 4)));
	i = -1;
	while (++i < 16)
		g_glob[g_cell_count].store[i / 4][i % 4] = 0;
	g_glob[g_cell_count].letter = g_cell_count + 'A';
	g_glob[g_cell_count].x = 0;
	g_glob[g_cell_count].y = 0;
	g_glob[g_cell_count].height = 0;
	g_glob[g_cell_count].width = 0;
}

void	fict1(void)
{
	int i;
	int j;

	i = 0;
	j = 6;
	while (++j < 29)
	{
		if (j % 6 > 0 && j % 6 < 5)
		{
			g_glob[g_cell_count].store[i / 4][i % 4] = g_st[j];
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
				g_st[6 * (i + 1) + 1 + j] = 1;
			else if ((*nl)[j] == '.')
				g_st[6 * (i + 1) + 1 + j] = 0;
			else
				error();
		}
		free(*nl);
	}
}

int		validate(int fd, size_t i, char *nl)
{
	i = -1;
	while (++i < 36)
		g_st[i] = 0;
	g_cell_count = -1;
	Z((g_glob = (t_huyna*)malloc(sizeof(t_huyna) * 28)));
	while (++g_cell_count < 26)
	{
		fict2(fd, &nl);
		globin();
		fict1();
		free(nl);
		if (get_next_line(fd, &nl) > 0)
		{
			if (ft_strlen(nl) != 0 || !val())
				error();
		}
		else
		{
			if (!val())
				error();
			free(nl);
			break ;
		}
		free(nl);
	}
	return (1);
}
