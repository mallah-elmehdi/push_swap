#include "../push_swap.h"

char	**ft_split(char *str, char delim, int length)
{
	char	**output;

	str = ft_strtrim(str, delim);
	output = (char **)malloc(sizeof(char *) * (length + 1));
	if (!output)
		return (NULL);
	output[length] = NULL;
	if (ft_token(str, delim, output, length))
		return (NULL);
	return (output);
}

int	*ft_atoi(char **output, int length)
{
	int	i;
	int	j;
	int	sign;
	int	*list;

	i = 0;
	list = (int *)ft_calloc(sizeof(int), length);
	while (i < length)
	{
		j = 0;
		list[i] = 0;
		sign = 1;
		if (output[i][j] == '-' && ++j)
			sign = -1;
		while (output[i][j] >= 48 && output[i][j] <= 57)
		{
			list[i] = (list[i] * 10) + (output[i][j] - 48);
			j++;
		}
		i++;
	}
	return (list);
}

char	*ft_join(char **av)
{
	int	i;
	int	j;
	int	k;
	int length;
	char *str;

	i = 1;
	k = 0;
	length = ft_av_length(av);
	str = (char *)ft_calloc(sizeof(char), length + 1);
	if (!str)
		return (NULL);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
			str[k++] = av[i][j++];
		if (k + 1 < length)
			str[k++] = ' ';
		i++;
	}
	return (str);
}

int	*ft_get_list(char *str)
{
	char **output;
	int length;

	length = ft_delim(str, ' ');
	output = ft_split(str, ' ', length);
	if (!output)
		return (NULL);
	if (ft_syntax(output, length))
		return (NULL);
	if (ft_duplicate(output, length))
		return (NULL);
	return (ft_atoi(output, length));
}