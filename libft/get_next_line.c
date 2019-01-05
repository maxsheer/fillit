/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 22:54:06 by wclayton          #+#    #+#             */
/*   Updated: 2019/01/05 22:53:11 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	findcur(t_list **lst, t_ci fd, t_list **tmp)
{
	t_list *iter;

	iter = *lst;
	while (iter)
	{
		if (iter->content_size == (size_t)fd)
		{
			*tmp = iter;
			return (0);
		}
		iter = iter->next;
	}
	LUPA((*tmp = ft_lstnew("\0", (size_t)fd)));
	ft_lstadd(lst, *tmp);
	*tmp = *lst;
	return (0);
}

int	fict(t_list **cur, int rd, char **rs)
{
	char *tmp;

	tmp = (*cur)->content;
	(*cur)->content = ft_strsub((t_cc*)((*cur)->content),
			rd + 1, ft_strlen((*cur)->content) - rd);
	free(tmp);
	if (!((*cur)->content))
	{
		ft_strclr(*rs);
		return (-1);
	}
	return (0);
}

int	stringf(t_list **cur, char **rs)
{
	int		rd;
	size_t	k;

	rd = 0;
	k = ft_strlen((*cur)->content);
	while (((char*)((*cur)->content))[rd] != '\n'
			&& (size_t)rd < k)
		rd++;
	free(*rs);
	LUPA((*rs = ft_strsub((t_cc*)((*cur)->content), 0, rd)));
	if ((size_t)rd < k)
	{
		PUPA(fict(&(*cur), rd, rs));
	}
	else
		ft_strclr((*cur)->content);
	return (1);
}

int	get_next_line(t_ci fd, char **rs)
{
	static t_list	*lst;
	t_list			*cur;
	int				rd;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;

	if (!rs || read(fd, buf, 0) < 0 || fd < 0)
		return (-1);
	LUPA((*rs = ft_strnew(1)));
	PUPA(findcur(&lst, fd, &cur));
	while ((rd = read(fd, buf, BUFF_SIZE)))
	{
		PUPA(rd);
		buf[rd] = 0;
		tmp = cur->content;
		cur->content = ft_strjoin(cur->content, buf);
		free(tmp);
		LUPA(cur->content);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ft_strlen(cur->content) == 0 && rd < BUFF_SIZE)
		return (0);
	return (stringf(&cur, rs));
}
