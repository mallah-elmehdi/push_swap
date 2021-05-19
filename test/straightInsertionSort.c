#include <stdio.h>

int main()
{
	int list[10] = {0, -5, 10, 4, 9, 6, -8, 1, 30, 2};
	int i = 0, j = 0, hold;

	// while (i < 10)
	// {
	// 	j = i;
	// 	while (j > 0)
	// 	{
	// 		if (list[j] < list[j - 1])
	// 		{
	// 			hold = list[j];
	// 			list[j] = list[j - 1];
	// 			list[j - 1] = hold;
	// 		}
	// 		else
	// 			break ;
	// 		j--;
	// 	}
	// 	i++;
	// }

	while (i < 10)
	{
		if (list[i] > list[i + 1])
		{
			hold = list[i];
			list[i] = list[i + 1];
			list[i + 1] = hold;
			i = -1;
		}
		i++;
	}
	
}