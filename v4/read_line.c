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

int check_error(char **str)
{
	if (syntax(str))
		return (ERROR);
	if (duplicate(str))
		return (ERROR);
	if (maxint(str))
		return (ERROR);
	return (SUCCESS);
}
