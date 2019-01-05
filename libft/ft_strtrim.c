/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 00:01:58 by wclayton          #+#    #+#             */
/*   Updated: 2018/11/26 02:09:16 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fict(const char *s, int *start, int *end)
{
	while (s[*start] == ' ' || s[*start] == '\t' || s[*start] == '\n')
		(*start)++;
	while ((s[*end - 1] == ' ' || s[*end - 1] == '\t' || s[*end - 1] == '\n')
			&& !(*end - 1 < 0))
		(*end)--;
}

char		*ft_strtrim(const char *s)
{
	int		start;
	int		end;
	int		size;
	char	*rslt;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	start = 0;
	end = size;
	ft_fict(s, &start, &end);
	if (end == 0)
		start = 0;
	rslt = (char*)malloc(sizeof(char) * (end - start + 1));
	if (rslt == NULL)
		return (NULL);
	rslt[end - start] = '\0';
	if (end == 0)
		return (rslt);
	size = -1;
	while (++size < end - start)
		rslt[size] = s[size + start];
	return (rslt);
}
