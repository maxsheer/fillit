/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wclayton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 20:43:38 by wclayton          #+#    #+#             */
/*   Updated: 2019/01/09 20:14:25 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include "./libft/libft.h"

# define Z(x) if (!x) write(1, "error\n", 6); exit;
# define MCHECK(x) if (x < 0) write(1, "error\n", 6); exit;

typedef unsigned char		t_uc;
typedef unsigned short		t_uz;

typedef struct				s_a
{
	t_uc					**store;
	t_uc					x;
	t_uc					y;
	t_uc					letter;
	t_uz					width;
	t_uz					height;
}							t_huyna;

t_huyna						*g_glob;
short						g_cell_count;
int							g_i;
t_uc						g_st[36];

int							usage(void);
int							validate(int fd, size_t i, char *nl);
void						cut(void);
void						hw(void);
void						algo(short size, char **map, short index);
void						print_solution(char	**map, short size);
char						**create_map(void);
int							find_size(short	cell_count);
void						error(void);
#endif
