/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:58:22 by wclayton          #+#    #+#             */
/*   Updated: 2018/11/26 04:53:03 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordsent(const char *str, char c)
{
	size_t	i;
	int		ent;

	i = 1;
	ent = 0;
	while (i <= ft_strlen(str))
	{
		if ((str[i] == c || str[i] == '\0') && str[i - 1] != c)
			ent++;
		i++;
	}
	return (ent);
}

static int	*wordsize(int ent, const char *str, char c)
{
	int *m;
	int k;
	int i;
	int s;

	i = 0;
	m = (int*)malloc(sizeof(int) * (ent + 1));
	if (m == NULL)
		return (NULL);
	m[ent] = 0;
	s = 0;
	while (i < ent)
	{
		k = 0;
		while (str[s] == c)
			s++;
		while (str[s] != '\0' && str[s] != c)
		{
			s++;
			k++;
		}
		m[i] = k;
		i++;
	}
	return (m);
}

static void	ft_fillbig(int *words, char **big, const char *str, char c)
{
	int i;
	int k;
	int j;
	int ent;

	i = 0;
	k = 0;
	ent = 0;
	while (words[ent] != 0)
		ent++;
	while (i < ent)
	{
		j = 0;
		while (str[k] == c)
			k++;
		while (j < words[i])
		{
			big[i][j] = str[k];
			k++;
			j++;
		}
		big[i][j] = '\0';
		i++;
	}
	big[i] = NULL;
}

char		**ft_strsplit(const char *str, char c)
{
	int		ent;
	int		*ws;
	int		i;
	char	**big;

	if (str == NULL)
		return (NULL);
	ent = wordsent(str, c);
	ws = wordsize(ent, str, c);
	big = (char**)malloc(sizeof(char*) * (ent + 1));
	if (big == NULL || ws == NULL)
		return (NULL);
	i = -1;
	while (++i < ent)
		big[i] = (char*)malloc(sizeof(char) * (ws[i] + 1));
	ft_fillbig(ws, big, str, c);
	free(ws);
	return (big);
}
