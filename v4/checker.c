#include "checker.h"

int	exec_ins(int *stack_a, int *stack_b, char *temp)
{
	update_temp(temp);
	if (ins_a(stack_a, stack_b, temp) == SUCCESS)
		return (SUCCESS);
	else if (ins_b(stack_a, stack_b, temp) == SUCCESS)
		return (SUCCESS);
	else if (ins_ab(stack_a, stack_b, temp) == SUCCESS)
		return (SUCCESS);
	else if (!temp[0])
		return (result(stack_a, stack_b));
	return (error());
}

int	free_all(int *stack_a, int *stack_b)
{
	free(stack_a);
	free(stack_b);
	return (SUCCESS);
}

int	read_data(char **str, char *temp)
{
	int	*stack_a;
	int	*stack_b;
	int	i;

	i = 0;
	stack_a = get_stack_a(str);
	stack_b = get_stack_b(str);
	if (!stack_a || !stack_b)
		return (error());
	while (read(0, &temp[i], 1))
	{
		if (temp[i] == '\n')
		{
			if (exec_ins(stack_a, stack_b, temp) == ERROR && \
				!free_all(stack_a, stack_b))
				return (ERROR);
			i = -1;
		}
		i++;
	}
	result(stack_a, stack_b);
	free(stack_a);
	free(stack_b);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	char	*temp;

	if (ac < 2)
		return (ERROR);
	temp = (char *)ft_calloc(sizeof(char), 5);
	if (!temp)
		return (ERROR);
	if (read_data(av, temp) == ERROR)
	{
		free(temp);
		return (ERROR);
	}
	free(temp);
	return (SUCCESS);
}
