#include "push_swap.h"

int	*get_stack_b(char **str)
{
	int	i;
	int	*temp;

	i = 0;
	temp = (int *)malloc(sizeof(int) * (ft_strlen_v2(str) + 1));
	if (!temp)
		return (NULL);
	while (i <= ft_strlen_v2(str))
	{
		temp[i] = -1;
		i++;
	}
	return (temp);
}

int	*get_list_index(char **str)
{
	int	i;
	int	*list;

	list = get_stack_b(str);
	i = 0;
	if (!list)
		return (NULL);
	while (str[i])
	{
		list[i] = i;
		i++;
	}
	return (list);
}

int	*get_stack_a(char **str)
{
	int	i;
	int	*temp;
	int	*temp2;

	i = 0;
	temp = get_list_index(str);
	if (!temp)
		return (NULL);
	temp2 = get_list_index(str);
	if (!temp)
		return (NULL);
	get_num_data(str, temp);
	while (i < ft_strlen_v2(str))
	{
		temp2[temp[i]] = i;
		i++;
	}
	free(temp);
	return (temp2);
}

char	**get_list(char **str)
{
	char	**temp;
	int		i;

	i = 0;
	if (syntax(str))
		return (NULL);
	temp = get_data(str);
	if (!temp)
		return (NULL);
	if (duplicate(temp))
		return (NULL);
	if (maxint(temp))
		return (NULL);
	return (temp);
}

char	**get_data(char **str)
{
	int		i;
	int		l;
	char	**temp;

	i = 1;
	l = 0;
	temp = (char **)ft_calloc_v2(sizeof(char *), delim(str));
	if (!temp)
		return (NULL);
	while (str[i])
	{
		if (has_space(str[i]) == SUCCESS)
		{
			while (has_space(str[i]))
				temp[l++] = ft_strcdup(str[i]);
		}
		else
			temp[l++] = ft_strdup(str[i]);
		i++;
	}
	return (temp);
}
