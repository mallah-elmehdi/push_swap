#include "../push_swap.h"

int	ft_syntax(char **output, int length)
{
	int i;
	int j;

	i = 0;
	while (i < length)
	{
		j = 0;
		while (output[i][j])
		{
			if ((output[i][j] < 48 || output[i][j] > 57) && output[i][j] != '-')
				return (ft_error());
			j++;
		}
		i++;
	}
	return (0);
}
