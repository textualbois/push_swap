#include "push_swap.h"

int	no_duplicates(int *arr)
{
	int i;
	int j;
	int len;

	len = arr[0];
	i = 1;
	while (i < len - 1)
	{
		j = i + j;
		while (j < len)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
