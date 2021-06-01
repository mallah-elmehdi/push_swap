NAME = push_swap
BN = checker
FILE = error.c instruction.c libtool_A.c libtool_B.c libtool_C.c libtool_D.c read_line.c sort.c special_case.c libchecker.c
PS =  push_swap.c
CH = checker.c

$(NAME):
	@gcc -Wall -Wextra -Werror -g -fsanitize=address $(FILE) $(PS) -o $(NAME)

all : $(NAME)

clean:
	@rm -fr push_swap.dSYM checker.dSYM

fclean: clean
	@rm -f $(NAME) $(BN)

re: fclean all

bonus:
	@gcc -Wall -Wextra -Werror -g -fsanitize=address $(FILE) $(CH) -o $(BN)