#include "push_swap.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	arrlen(int *list)
{
	int		i;

	i = 0;
	while (list[i] != -1)
		i++;
	return (i);
}

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (SUCCESS);
	return (ERROR);
}

int	ft_strlen_v2(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	get_num_data(char **str, int *temp)
{
	int	i;
	int	val;

	i = 0;
	while (i < ft_strlen_v2(str) - 1)
	{
		if (ft_atoi(str[temp[i]]) > ft_atoi(str[temp[i + 1]]))
		{
			val = temp[i];
			temp[i] = temp[i + 1];
			temp[i + 1] = val;
			i = -1;
		}
		i++;
	}
}
