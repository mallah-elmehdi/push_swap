#include "../push_swap.h"

void	*ft_calloc(int a, int b)
{
	int		i;
	void	*output;

	i = 0;
	output = malloc(a * b);
	if (!output)
		return (NULL);
	while (i < (a * b))
	{
		((unsigned char *)output)[i] = '\0';
		i++;
	}
	return (output);
}

int	ft_free_v2(char **str, int a)
{
	int	i;

	i = 0;
	while (i < a)
	{
		free(str[i]);
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_av_length(char **av)
{
	int	i;
	int	j;
	int	length;

	i = 1;
	length = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{	
			length++;
			j++;
		}
		length++;
		i++;
	}
	return (length);
}