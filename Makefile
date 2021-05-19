NAME = push_swap

EROOR =	error/duplicate.c error/tool.c error/syntax.c
TOOLS = tools/pack_a.c tools/pack_b.c tools/pack_c.c
SORT = sort/sort.c
MAIN = main.c

$(NAME):
	@gcc  -fsanitize=address $(EROOR) $(TOOLS) $(SORT) $(MAIN) -o $(NAME)
all : $(NAME)

clean:
	@rm -fr *.o a.out file_test a.out.dSYM

fclean: clean
	@rm -f $(NAME)

re: fclean all