# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgrady <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/05 22:26:30 by dgrady            #+#    #+#              #
#    Updated: 2019/01/05 23:06:54 by dgrady           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = error.c usage.c validate.c main.c algorithm.c cut.c hw.c stuff.c

OBS=$(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc -Wall -Wextra -Werror -c $(SRC) 
	@gcc -Wall -Wextra -Werror -o $(NAME) -Ilibft -Llibft -lft $(OBS)

clean:
	@make -C libft/ fclean
	@rm -f $(OBS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
