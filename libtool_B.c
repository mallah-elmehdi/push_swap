#include "push_swap.h"

char	*ft_calloc(int a, int b)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)malloc(a * b);
	if (!p)
		return (NULL);
	while (i < a * b)
		p[i++] = 0;
	return (p);
}

long	ft_atoi(char *str)
{
	long	a;
	int		i;
	int		sign;

	i = 0;
	a = 0;
	while (str[i])
	{
		sign = 1;
		if (str[i] == '-')
		{
			i++;
			sign = -1;
		}
		while (str[i] >= 48 && str[i] <= 57)
		{
			if (a * sign > MAXINT || a * sign < MININT)
				return (a * sign);
			a = (a * 10) + (str[i++] - 48);
		}
		if (str[i])
			i++;
	}
	return (a * sign);
}

void	free_2(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}
