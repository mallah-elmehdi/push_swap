#include "push_swap.h"

void	case_3(int *list, char c)
{
	if (c == 'b')
	{
		if ((list[1] > list[0] && list[1] < list[2])
			|| (list[0] > list[2] && list[0] < list[1])
			|| (list[2] > list[1] && list[2] < list[0]))
			s(list, c);
		else if (list[1] < list[0] && list[0] < list[2])
			rr(list, c);
		else
			r(list, c);
	}
	else if (c == 'a')
	{
		if ((list[1] < list[0] && list[1] > list[2])
			|| (list[0] > list[1] && list[0] < list[2])
			|| (list[2] < list[1] && list[2] > list[0]))
			s(list, c);
		else if (list[0] > list[1] && list[0] < list[2])
			rr(list, c);
		else
			r(list, c);
	}
}

void	case_5(int *stack_a, int *stack_b)
{
	int	i;

	i = get_min_index(stack_a);
	if (i == 1)
		s(stack_a, 'a');
	else if (i <= (arrlen(stack_a) - 1) / 2)
	{
		while (i--)
			r(stack_a, 'a');
	}
	else
	{
		while (i++ < arrlen(stack_a))
			rr(stack_a, 'a');
	}
	p(stack_a, stack_b, 'b');
	if (arrlen(stack_b) == 2 && sorted(stack_b, 1) == ERROR)
		s(stack_b, 'b');
}
