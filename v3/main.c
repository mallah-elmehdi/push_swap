#include "push_swap.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_arrlen(int *list)
{
	int		i;

	i = 0;
	while (list[i] != -1)
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
		{
			if (a > MAXINT)
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

int	ft_maxint(char **str)
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

int	get_max_index(int *list)
{
	int index;
	int i;

	index = 0;
	i = 0;
	while (i < ft_arrlen(list))
	{
		if (list[index] < list[i])
			index = i;
		i++;
	}
	return (index);
}
int	get_min_index(int *list)
{
	int index;
	int i;

	index = 0;
	i = 0;
	while (i < ft_arrlen(list))
	{
		if (list[index] > list[i])
			index = i;
		i++;
	}
	return (index);
}
void	move_list(int *list)
{
	int i;

	i = ft_arrlen(list);
	while (i > 0)
	{
		list[i] = list[i - 1];
		i--;
	}
}

void	s(int *list, char ins)
{
	int	temp;

	temp = list[0];
	list[0] = list[1];
	list[1] = temp;
	if (ins)
	{
		write(1, "s", 1);
		write(1, &ins, 1);
		write(1, "\n", 1);
	}
}

void	rr(int *list, char ins)
{
	int	temp;
	int i;

	i = ft_arrlen(list) - 1;
	while (i > 0)
	{
		temp = list[i];
		list[i] = list[i - 1];
		list[i - 1] = temp;
		i--;
	}
	if (ins)
	{
		write(1, "rr", 2);
		write(1, &ins, 1);
		write(1, "\n", 1);
	}
}

void	r(int *list, char ins)
{
	int	temp;
	int i;

	i = 0;
	while (i < ft_arrlen(list) - 1)
	{
		temp = list[i];
		list[i] = list[i + 1];
		list[i + 1] = temp;
		i++;
	}
	if (ins)
	{
		write(1, "r", 1);
		write(1, &ins, 1);
		write(1, "\n", 1);
	}
}

void	p(int *from, int *to, char ins)
{
	int i;

	i = 0;
	move_list(to);
	to[0] = from[0];
	while (i < ft_arrlen(from) - 1)
	{
		from[i] = from[i + 1];
		i++;
	}
	from[i] = -1;
	if (ins)
	{
		write(1, "p", 1);
		write(1, &ins, 1);
		write(1, "\n", 1);
	}
}


void	ft_case(int *list, char c)
{
	if (c == 'b')
	{
		if ((list[1] > list[0] && list[1] < list[2])
		|| (list[0] > list[2] && list[0] < list[1])
		|| (list[2] > list[1] && list[2] < list[0]))
			s(list, c);
		else if (list[1] < list[0] && list[0] < list[2])
			rr(list, c);
		else
			r(list, c);
	}
	else if (c == 'a')
	{
		if ((list[1] < list[0] && list[1] > list[2])
		|| (list[0] > list[1] && list[0] < list[2])
		|| (list[2] < list[1] && list[2] > list[0]))
			s(list, c);
		else if (list[0] > list[1] && list[0] < list[2])
			rr(list, c);
		else
			r(list, c);
	}
}

int ft_sorted(int *list, int vect)
{
	int i;

	i = 0;
	if (vect == 1)
	{
		while (i < ft_arrlen(list) - 1)
		{
			if (list[i] < list[i + 1])
				return (ERROR);
			i++;
		}
	}
	else if (vect == -1)
	{
		while (i < ft_arrlen(list) - 1)
		{
			if (list[i] > list[i + 1])
				return (ERROR);
			i++;
		}
	}
	return (SUCCESS);
}

void	sort_help(int *list, char c)
{
	int i;
	int it;

	i = ft_arrlen(list) - 1;
	it = 0;
	while (i > 0 && list[0] > list[i])
	{
		i--;
		it++;
	}
	while (it)
	{
		rr(list, c);
		s(list, c);
		it--;
	}
	while (ft_sorted(list, 1) == ERROR)
		r(list, c);
}

void	sort_desc(int *list, char c)
{
	while (ft_arrlen(list) > 1 && ft_sorted(list, 1) == ERROR)
	{
		if (ft_arrlen(list) == 2)
			s(list, c);
		else if (ft_arrlen(list) == 3)
			ft_case(list, 'b');
		else
			sort_help(list, c);
	}
}

int		check_stack(int *list, int max)
{
	int i;

	i = 0;
	while (i < ft_arrlen(list))
	{
		if (list[i] < max)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

// void	sort_num(int *stack_a, int *stack_b, int length)
// {
// 	int i;
// 	int part;

// 	i = 1;
// 	part = ft_arrlen(stack_a) / 10;
// 	while (i <= 10)
// 	{
// 		while (check_stack(stack_a, part * i) == ERROR)
// 		{
// 			if (stack_a[0] <= part * i)
// 			{
// 				p(stack_a, stack_b, 'b');
// 				sort_desc(stack_b, 'b');
// 			}
// 			else
// 				r(stack_a, 'a');
// 		}
// 		i++;
// 	}
// }

int	get_down(int *list, int max)
{
	int i;
	int down;

	i =  get_min_index(list);;
	down = 0;
	while (i < ft_arrlen(list) && i <= max)
	{
		i++;
		down++;
	}
	return (down);
}

int	get_up(int *list, int max)
{
	int i;
	int up;

	i =  get_min_index(list);;
	up = 0;
	while (i >= 0 && i <= max)
	{
		i--;
		up++;
	}
	return (up);
}

void	sort_num(int *stack_a, int *stack_b, int length)
{
	int i;
	int part;
	int up;
	int down;

	i = 1;
	part = ft_arrlen(stack_a) / 5;
	while (i <= 5 && ft_arrlen(stack_a) > 3)
	{
		up = get_up(stack_a, part * i);
		down = get_down(stack_a, part * i);
		if (down > up)
		{
			if (get_min_index(stack_a) < ft_arrlen(stack_a) - get_min_index(stack_a) - down - 1)
			{
				while (get_min_index(stack_a) != 0)
					r(stack_a, 'a');
			}
			else
			{
				while (get_min_index(stack_a) != 0)
					rr(stack_a, 'a');
			}
			while (down--)
			{
				p(stack_a, stack_b, 'b');
				sort_desc(stack_b, 'b');
			}
		}
		else
		{
			if (get_min_index(stack_a) < ft_arrlen(stack_a) - get_min_index(stack_a) - up - 1)
			{
				while (get_min_index(stack_a) != 0)
					r(stack_a, 'a');
			}
			else
			{
				while (get_min_index(stack_a) != 0)
					rr(stack_a, 'a');
			}
			while (down--)
			{
				p(stack_a, stack_b, 'b');
				sort_desc(stack_b, 'b');
			}
		}
		i++;
	}
}

void	sort_all(int *stack_a, int *stack_b)
{
	int length;
	
	length = ft_arrlen(stack_a) / 2;
	while (ft_sorted(stack_a, -1) == ERROR)
	{
		if (ft_arrlen(stack_a) == 2)
			s(stack_a, 'a');
		else if (ft_arrlen(stack_a) == 3)
			ft_case(stack_a, 'a');
		else
			sort_num(stack_a, stack_b, length);
	}
	while (ft_arrlen(stack_b))
		p(stack_b, stack_a, 'a');
}

int	*get_stack_b(char **str)
{
	int i;
	int *temp;

	i = 0;
	temp = (int* )malloc(sizeof(int) * (ft_strlen_v2(str) + 1));
	if (!temp)
		return (NULL);
	while (i <= ft_strlen_v2(str))
	{
		temp[i] = -1;
		i++;
	}
	return (temp);
}

int *get_list_index(char **str)
{
    int i;
    int *list;
    
    list = get_stack_b(str);
    if (!list)
        return (NULL);
    i = 0;
    while (str[i])    
    {
        list[i] = i;
        i++;
    }
    return (list);
}

int	*get_stack_a(char **str)
{
	int i;
	int val;
	int *temp;
	int *temp2;

	i = 0;
	temp = get_list_index(str);
	if (!temp)
		return (NULL);
	temp2 = get_list_index(str);
	if (!temp)
		return (NULL);
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
	i = 0;
    while (i < ft_strlen_v2(str))
    {
		temp2[temp[i]] = i;
		i++;
    }
	free(temp);
	return (temp2);
}

int	sort(char **str)
{
	int	*stack_a;
	int	*stack_b;

	stack_a = get_stack_a(str);
	stack_b = get_stack_b(str);
	if (!stack_a || !stack_b)
		return (ft_error());
	sort_all(stack_a, stack_b);
	free(stack_a);
	free(stack_b);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	char	**stack_a;

	if (ac < 2)
		return (ERROR);
	stack_a = ft_get_list(av);
	if (!stack_a)
		return (ERROR);
	if (sort(stack_a) == ERROR)
		return (ERROR);
	free_2(stack_a);
	return (SUCCESS);
}

// ARG=`ruby -e "puts (-1..4).to_a.shuffle.join(' ')"` && ./push_swap $ARG