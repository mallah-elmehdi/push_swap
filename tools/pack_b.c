#include "../push_swap.h"

char	*ft_fill(char *str, char delim, char *token)
{
	int		i;

	i = 0;
	while (*str && *str != delim)
	{
		token[i] = *str;
		str++;
		i++;
	}
	return (ft_trim(str, delim));
}

char	*ft_strtrim(char *str, char delim)
{
	int	i;

	while (*str && *str == delim)
		str++;
	i = ft_strlen(str) - 1;
	while (i >= 0 && str[i] == delim)
		i--;
	str[i + 1] = 0;
	return (str);
}

int	ft_token(char *str, char delim, char **output, int length)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < length)
	{
		j = 0;
		while (str[j] != delim)
			j++;
		output[i] = (char *)ft_calloc(sizeof(char), j + 1);
		if (!output[i])
			return (ft_free_v2(output, i));
		str = ft_fill(str, delim, output[i]);
		i++;
	}
	return (0);
}

int	ft_delim(char *str, char delim)
{
	int		i;
	int		lenght;

	i = 0;
	lenght = 0;
	while (str[i])
	{
		if (str[i] == delim)
		{
			lenght++;
			while (str[i] == delim)
				i++;
		}
		i++;
	}
	return (lenght + 1);
}

char	*ft_trim(char *str, char delim)
{
	while (*str && *str == delim)
		str++;
	return (str);
}
