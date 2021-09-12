#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac < 2)
		return (ERROR);
	if (check_error(av) == ERROR)
		return (ERROR);
	if (sort(av) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
