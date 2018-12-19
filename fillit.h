/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 20:43:38 by wclayton          #+#    #+#             */
/*   Updated: 2018/12/19 22:53:53 by wclayton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include "./libft/libft.h"
# include "get_next_line.h"
# define ZCHECK(x) if (!x) return (-1);
# define MCHECK(x) if (x < 0) write(1, "govna poel\n", 11); exit;

typedef unsigned char	t_uc;
typedef unsigned short t_uz;


typedef struct	t_a
{
				t_uc **store;
}				t_huyna;

t_huyna g_glob;

int	usage(void);
int validate(int fd);
int cut(void);
#endif