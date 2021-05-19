#include "../push_swap.h"

int	ft_duplicate(char **output, int length)
{
	int i;
	int j;

	i = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (output[i] == output[j])
				return (ft_error());
			j++;
		}
		i++;
	}
	return (0);
}
