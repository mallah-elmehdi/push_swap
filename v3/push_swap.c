#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**stack_a;

	if (ac < 2)
		return (ERROR);
	stack_a = get_list(av);
	if (!stack_a)
		return (ERROR);
	if (sort(stack_a) == ERROR)
		return (ERROR);
	free_2(stack_a);
	return (SUCCESS);
}
