#include "push_swap.h"
int main(int ac, char **av)
{

	int *list;
	char *str;

	if (ac < 2)
		return (ft_error());
	str = ft_join(av);
	if (!str)
		return (ft_error());
	list = ft_get_list(str);
	// if (!list)
	// 	return (ft_error());
	// sort(list);
}