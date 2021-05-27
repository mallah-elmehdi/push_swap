NAME = push_swap

$(NAME):
	@gcc -g -fsanitize=address main.c -o $(NAME)
all : $(NAME)

clean:
	@rm -fr *.o a.out file_test a.out.dSYM

fclean: clean
	@rm -f $(NAME)

re: fclean all