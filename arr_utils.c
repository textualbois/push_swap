#include "push_swap.h"

size_t	ft_arrlen(char **arr)
{
	size_t	res;

	res = 0;
	while (arr[res] != NULL)
		res++;
	return (res);
}

void	*clear_arr(char **res_arr)
{
	size_t	count;
	size_t	arr_len;

	count = 0;
	arr_len = ft_arrlen(res_arr);
	while (count < arr_len)
	{
		free(res_arr[count]);
		res_arr[count] = NULL;
		count++;
	}
	free(res_arr);
	return (NULL);
}

void	rm_el(char **arr, int index, int arr_len)
{
	int		i;
	char	**res;
	int		j;
	
	res = malloc(sizeof(char *) * arr_len);
	if (res == NULL)
		return (werror("Error\n", 2));
	i = 0;
	j = 0;
	while (i < arr_len)
	{	
		j = (i >= index);
		res[i] = malloc(ft_strlen(arr[i + j] + 1));
		if (res[i] == NULL)
		{
			res = clear_arr(res);
			return (werror("Error\n", 2));
		}
		ft_strlcpy(res[i], arr[i + j], ft_strlen(arr[i + j]));
		i++;
	}
	res[i] = NULL;
}
