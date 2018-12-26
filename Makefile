all:
	@make -C libft/
	@make -C libft/ clean
	@gcc -o fillit -Ilibft -Llibft -lft *.c
clean:
	@rm -f *.o
fclean: clean
	@rm -f fillit
re: fclean all
