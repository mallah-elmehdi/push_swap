#include "push_swap.h"

int	syntax(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '-' && is_num(str[i][j + 1]) == ERROR)
				return (error());
			else if (is_num(str[i][j]) == ERROR && str[i][j] != '-')
				return (error());
			else if (is_num(str[i][j]) == SUCCESS && str[i][j + 1] == '-')
				return (error());
			j++;
		}
		i++;
	}
	return (0);
}

int	duplicate(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi(str[j]) == ft_atoi(str[i]))
				return (error());
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	maxint(char **str)
{	
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_atoi(str[i]) > MAXINT || ft_atoi(str[i]) < MININT)
			return (error());
		i++;
	}
	return (SUCCESS);
}

int	error(void)
{
	write(2, "Error\n", 6);
	return (ERROR);
}
