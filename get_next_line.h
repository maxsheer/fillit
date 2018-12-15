/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 21:56:06 by wclayton          #+#    #+#             */
/*   Updated: 2018/12/14 22:24:13 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 21
# define PUPA(x) if (x < 0) return (-1);
# define LUPA(x) if (!x) return (-1);

typedef const int	t_ci;
typedef const char	t_cc;
int					get_next_line(const int fd, char **rs);

#endif
