#include "push_swap.h"

int	get_down(int *list, int max)
{
	int	i;

	i = arrlen(list) - 1;
	while (i >= 0)
	{
		if (list[i] <= max)
			return (i);
		i--;
	}
	return (i);
}

int	get_up(int *list, int max)
{
	int	i;

	i = 0;
	while (i < arrlen(list))
	{
		if (list[i] <= max)
			return (i);
		i++;
	}
	return (i);
}

int	check_stack(int *list, int max)
{
	int	i;

	i = 0;
	while (i < arrlen(list))
	{
		if (list[i] <= max)
			return (SUCCESS);
		i++;
	}
	return (ERROR);
}

int	get_max_index(int *list)
{
	int	index;
	int	i;

	index = 0;
	i = 0;
	while (i < arrlen(list))
	{
		if (list[index] < list[i])
			index = i;
		i++;
	}
	return (index);
}

int	get_min_index(int *list)
{
	int	index;
	int	i;

	index = 0;
	i = 0;
	while (i < arrlen(list))
	{
		if (list[index] > list[i])
			index = i;
		i++;
	}
	return (index);
}
