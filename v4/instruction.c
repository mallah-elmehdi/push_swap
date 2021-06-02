#include "push_swap.h"

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
	int	i;

	i = arrlen(list) - 1;
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
	int	i;

	i = 0;
	while (i < arrlen(list) - 1)
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
	int	i;

	i = 0;
	move_list(to);
	to[0] = from[0];
	while (i < arrlen(from) - 1)
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

void	move_list(int *list)
{
	int	i;

	i = arrlen(list);
	while (i > 0)
	{
		list[i] = list[i - 1];
		i--;
	}
}
