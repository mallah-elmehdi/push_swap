#include "push_swap.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (ERROR);
}

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (SUCCESS);
	return (ERROR);
}

int	ft_syntax(char **str)
{
	int i;
	int j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '-' && is_num(str[i][++j]))
				return (ft_error());
			else if (is_num(str[i][j]) && str[i][j] != ' ')
				return (ft_error());
			j++;
		}
		i++;
	}
	return (0);
}



int	ft_strlen_v2(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_delim(char **str)
{
	int		i;
	int		j;
	int		lenght;

	i = 1;
	j = 0;
	lenght = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!is_num(str[i][j]))
			{
				lenght++;
				while (str[i][j + 1] && !is_num(str[i][j]))
					j++;
			}
			j++;
		}
		i++;
	}
	return (lenght + 1);
}

char	**ft_calloc_v2(int a, int b)
{
	int i;
	char	**p;

	i = 0;
	p = (char **)malloc(a * b);
	if (!p)
		return (NULL);
	while (i < b)
		p[i++] = NULL;
	return (p);
}

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

char	**ft_get_data(char **str)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	**temp;

	i = 1;
	l = 0;
	temp = (char **)ft_calloc_v2(sizeof(char *), ft_delim(str));
	if (!temp)
		return (NULL);
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!is_num(str[i][j]) || str[i][j] == '-')
			{
				k = 0;
				temp[l] = (char *)ft_calloc(sizeof(char), ft_strlen(str[i]) + 1);
				if (!temp[l])
					return (NULL);
				while (!is_num(str[i][j]) || str[i][j] == '-')
					temp[l][k++] = str[i][j++];
				l++;
			}
			if (str[i][j])
				j++;
		}
		i++;
	}
	return (temp);
}

long	ft_atoi(char *str)
{
	long	a;
	int	i;
	int	sign;

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
			a = (a * 10) + (str[i++] - 48);
		if (str[i])
			i++;
	}
	return (a * sign);
}

char	*ft_strdup(char *str)
{
	int i;
	char *temp;

	temp = (char *)ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!temp)
		return (NULL);
	i = 0;
	while (str[i])
	{
		temp[i] = str[i];
		i++;
	}
	return (temp);
}

void	free_2(char **str)
{
	int i;

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

int	ft_duplicate(char **str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (!ft_strcmp(str[j], str[i]))
				return (ft_error());
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

char	**ft_maxint(char **str)
{	
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_atoi(str[i]) > MAXINT)
			return (ft_error());
		i++;
	}
	return (SUCCESS);
}

char	**ft_get_list(char **str)
{
	char **temp;
	int	i;

	i = 0;
	if (ft_syntax(str))
		return (NULL);
	temp = ft_get_data(str);
	if (!temp)
		return (NULL);
	if (ft_duplicate(temp))
		return (NULL);
	if (ft_maxint(temp))
		return (NULL);
	return (temp);
}

int	get_min_index(char **str)
{
	int index;
	int i;

	index = 0;
	i = 0;
	while (str[i])
	{
		if (ft_atoi(str[index]) > ft_atoi(str[i]))
			index = i;
		i++;
	}
	return (index);
}

char	*sa(char **str)
{
	char *temp;

	temp = ft_strdup(str[0]);
	if (!temp)
		return (NULL);
	free(str[0]);
	str[0] = ft_strdup(str[1]);
	if (!str[0])
		return (NULL);
	free(str[1]);
	str[1] = ft_strdup(temp);
	if (!str[1])
		return (NULL);
	free(temp);
	write(1, "sa\n", 3);
	return (*str);
}

char	*rra(char **str)
{
	char *temp;
	int i;

	i = ft_strlen_v2(str) - 1;
	while (i > 0)
	{
		temp = ft_strdup(str[i]);
		if (!temp)
			return (NULL);
		free(str[i]);
		str[i] = ft_strdup(str[i - 1]);
		if (!str[i])
			return (NULL);
		free(str[i - 1]);
		str[i - 1] = ft_strdup(temp);
		if (!str[i - 1])
			return (NULL);
		free(temp);
		i--;
	}
	write(1, "rra\n", 4);
	return (*str);
}

char	*ra(char **str)
{
	char *temp;
	int i;

	i = 0;
	while (i < ft_strlen_v2(str) - 1)
	{
		temp = ft_strdup(str[i]);
		if (!temp)
			return (NULL);
		free(str[i]);
		str[i] = ft_strdup(str[i + 1]);
		if (!str[i])
			return (NULL);
		free(str[i + 1]);
		str[i + 1] = ft_strdup(temp);
		if (!str[i + 1])
			return (NULL);
		free(temp);
		i++;
	}
	write(1, "ra\n", 3);
	return (*str);
}

char	*pb(char **stack_a, char **stack_b)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen_v2(stack_b);

	while (j > 0)
	{
		stack_b[j] = ft_strdup(stack_b[j - 1]);
		if (!stack_b[j])
			return (NULL);
		free(stack_b[j - 1]);
		j--;
	}

	stack_b[0] = ft_strdup(stack_a[0]);
	if (!stack_b[0])
		return (NULL);
	while (i < ft_strlen_v2(stack_a) - 1)
	{
		// free(stack_a[i]);
		stack_a[i] = ft_strdup(stack_a[i + 1]);
		if (!stack_a[i])
			return (NULL);
		free(stack_a[i + 1]);
		i++;
	}
	stack_a[i] = NULL;
	write(1, "pb\n", 3);
	return ("GOOD");
}

char	*pa(char **stack_a, char **stack_b)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen_v2(stack_a);

	while (j > 0)
	{
		stack_a[j] = ft_strdup(stack_a[j - 1]);
		if (!stack_a[j])
			return (NULL);
		free(stack_a[j - 1]);
		j--;
	}

	stack_a[0] = ft_strdup(stack_b[0]);
	if (!stack_a[0])
		return (NULL);
	while (i < ft_strlen_v2(stack_b) - 1)
	{
		// free(stack_b[i]);
		stack_b[i] = ft_strdup(stack_b[i + 1]);
		if (!stack_b[i])
			return (NULL);
		free(stack_b[i + 1]);
		i++;
	}
	stack_b[i] = NULL;
	write(1, "pa\n", 3);
	return ("GOOD");
}

char	*sort_a(char **stack_a, char **stack_b, int index)
{
	if (index == 1)
	{
		if (!sa(stack_a))
			return (NULL);
	}
	else if (index == 0)
	{
		if (!pb(stack_a, stack_b))
			return (NULL);

	}
	else if (index > ft_strlen_v2(stack_a) / 2) {
		while (index < ft_strlen_v2(stack_a)) {			
			if (!rra(stack_a))
				return (NULL);
			index++;
		}
	}
	else {
		while (index > 0) {			
			if (!ra(stack_a))
				return (NULL);
			index--;
		}
	}
	return ("GOOD");
}

int ft_sorted(char **str)
{
	int i;

	i = 0;
	while (i < ft_strlen_v2(str) - 1)
	{
		if (ft_atoi(str[i]) > ft_atoi(str[i + 1]))
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	sort(char **stack_a)
{
	int index;
	char	**stack_b;

	stack_b = (char **)ft_calloc_v2(sizeof(char *), ft_strlen_v2(stack_a) + 1);
	if (!stack_b)
		return (ft_error());
	while (ft_sorted(stack_a) == ERROR)
	{
		index = get_min_index(stack_a);
		if (!sort_a(stack_a, stack_b, index))
			return (ft_error());
	}
	while (ft_strlen_v2(stack_b))
	{
		if (!pa(stack_a, stack_b))
			return (ft_error());
	}
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	char	**stack_a;

	if (ac < 2)
		return (SUCCESS);
	stack_a = ft_get_list(av);
	if (!stack_a)
		return (ERROR);
	if (sort(stack_a) == ERROR)
		return (ERROR);
	return (SUCCESS);
}


// ARG=`ruby -e "puts (-1..4).to_a.shuffle.join(' ')"` && ./push_swap $ARG