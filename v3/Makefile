NAME = push_swap
BONUS = checker
FILE = error.c instruction.c libtool_A.c libtool_B.c libtool_C.c libtool_D.c read_line.c sort.c special_case.c libchecker.c
PS =  push_swap.c
CH = checker.c

$(NAME):
	@gcc -Wall -Wextra -Werror $(FILE) $(PS) -o $(NAME)

$(BONUS):
	@gcc -Wall -Wextra -Werror $(FILE) $(CH) -o $(BONUS)

all : $(NAME)

clean:
	@rm -fr push_swap.dSYM checker.dSYM

fclean: clean
	@rm -f $(NAME) $(BONUS)

re: fclean all

bonus: $(BONUS)