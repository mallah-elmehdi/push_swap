#include "push_swap.h"

int	delim(char **str)
{
	int	i;
	int	j;
	int	lenght;

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

int	has_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (SUCCESS);
		i++;
	}
	return (ERROR);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!temp)
		return (NULL);
	while (str[i])
	{
		temp[i] = str[i];
		i++;
	}
	return (temp);
}

char	*ft_strcdup(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!temp)
		return (NULL);
	while (*str == ' ')
		str++;
	while (str[1] && *str != ' ')
		temp[i++] = (*str)++;
	return (temp);
}
