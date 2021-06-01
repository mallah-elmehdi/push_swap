#include "checker.h"

void	update_temp(char *temp)
{
	int	i;

	i = 0;
	while (i < ft_strlen(temp))
	{
		if (temp[i] == '\n')
		{
			temp[i] = '\0';
			break ;
		}
		i++;
	}
}

int	ins_a(int *stack_a, int *stack_b, char *temp)
{
	if (!ft_strcmp(temp, "sa"))
	{
		s(stack_a, 0);
		return (SUCCESS);
	}
	else if (!ft_strcmp(temp, "ra"))
	{
		r(stack_a, 0);
		return (SUCCESS);
	}
	else if (!ft_strcmp(temp, "rra"))
	{
		rr(stack_a, 0);
		return (SUCCESS);
	}
	else if (!ft_strcmp(temp, "pa"))
	{
		p(stack_b, stack_a, 0);
		return (SUCCESS);
	}
	return (ERROR);
}

int	ins_b(int *stack_a, int *stack_b, char *temp)
{
	if (!ft_strcmp(temp, "sb"))
	{
		s(stack_b, 0);
		return (SUCCESS);
	}
	else if (!ft_strcmp(temp, "rb"))
	{
		r(stack_b, 0);
		return (SUCCESS);
	}
	else if (!ft_strcmp(temp, "rrb"))
	{
		rr(stack_b, 0);
		return (SUCCESS);
	}
	else if (!ft_strcmp(temp, "pb"))
	{
		p(stack_a, stack_b, 0);
		return (SUCCESS);
	}
	return (ERROR);
}

int	ins_ab(int *stack_a, int *stack_b, char *temp)
{
	if (!ft_strcmp(temp, "rr"))
	{
		r(stack_b, 0);
		r(stack_a, 0);
		return (SUCCESS);
	}
	else if (!ft_strcmp(temp, "rrr"))
	{
		rr(stack_b, 0);
		rr(stack_a, 0);
		return (SUCCESS);
	}
	return (ERROR);
}

void	result(int *stack_a, int *stack_b)
{
	if (arrlen(stack_b) > 0 || sorted(stack_a, -1) == ERROR)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}
