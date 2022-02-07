#include "push_swap.h"


int	sort(char **str)
{
	int	*stack_a;
	int	*stack_b;

	stack_a = get_stack_a(str);
	stack_b = get_stack_b(str);
	if (!stack_a || !stack_b)
		return (error());
	sort_all(stack_a, stack_b);
	free(stack_a);
	free(stack_b);
	return (SUCCESS);
}

void	sort_all(int *stack_a, int *stack_b)
{
	int	i;
	int	max_part;

	i = 1;
	max_part = 30;
	if (arrlen(stack_a) <= 200)
		max_part = 20;
	while (sorted(stack_a, -1) == ERROR)
	{
		if (arrlen(stack_a) == 2)
			s(stack_a, 'a');
		else if (arrlen(stack_a) == 3)
			case_3(stack_a, 'a');
		else if (arrlen(stack_a) <= 5)
			case_5(stack_a, stack_b);
		else
			sort_num(stack_a, stack_b, max_part * i++);
	}
	sort_a(stack_a, stack_b);
}

void	sort_a(int *stack_a, int *stack_b)
{
	int	index;

	while (arrlen(stack_b))
	{
		index = get_max_index(stack_b);
		if (!index)
			p(stack_b, stack_a, 'a');
		else if (index == 1)
			s(stack_b, 'b');
		else if (index < (arrlen(stack_b) - 1) / 2)
		{
			while (index--)
				r(stack_b, 'b');
		}
		else
		{
			while (index++ < arrlen(stack_b))
				rr(stack_b, 'b');
		}
	}
}

void	sort_num(int *stack_a, int *stack_b, int max)
{
	int	up;
	int	down;

	while (check_stack(stack_a, max) == SUCCESS)
	{
		up = get_up(stack_a, max);
		down = get_down(stack_a, max);
		if (up <= arrlen(stack_a) - 1 - down)
		{
			while (up--)
				r(stack_a, 'a');
		}
		else
		{
			while (down++ < arrlen(stack_a))
				rr(stack_a, 'a');
		}
		p(stack_a, stack_b, 'b');
	}
}

int	sorted(int *list, int vect)
{
	int	i;

	i = 0;
	if (vect == 1)
	{
		while (i < arrlen(list) - 1)
		{
			if (list[i] < list[i + 1])
				return (ERROR);
			i++;
		}
	}
	else if (vect == -1)
	{
		while (i < arrlen(list) - 1)
		{
			if (list[i] > list[i + 1])
				return (ERROR);
			i++;
		}
	}
	return (SUCCESS);
}
