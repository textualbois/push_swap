#include "push_swap.h"

int *parse_check(int argc, char **argv)
{
	int i;
	int *res;

	pre_parse(&argc, &argv);
	if (argv == NULL || argc < 2)
		return (werror("Error\n", 2));
	i = 0;
	res = (int *)malloc(sizeof(int) * argc);
	if (res != NULL)
	{
		argv = clear_arr(argv);
		return (werror("Error\n", 2));
	}
	while (i < argc)
	{
		if(is_int(argv[i]))
			res[i] = ft_atoi(argv[i]);
		else
		{
			res = clear_arr(res);
			return (werror("Error\n", 2));
		}

	}
}

void	pre_parse(int *argc, char ***argv)
{
	if (argc > 2)
		rm_el(*argv, 0, *argc);
	if (*argc == 2)
	{
		*argv == ft_split(*argv[1], ' ');
		*argc = ft_arrlen(*argv);
	}
}

int	**map_s_2_i(int argc, char **argv, int offset)
{
	int	**res;
	int	arr_i;

	res = malloc((ft_arrlen(argv) + 1) * sizeof(char **));
	arr_i = 0;
	while (arr[arr_i] != NULL)
	{
		res[arr_i] = f(arr[arr_i], str);
		if (res[arr_i] == NULL)
		{
			clear_arr(res);
			return (NULL);
		}
		arr_i++;
	}
	res[arr_i] = NULL;
	return (res);
}
