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
	if (res == NULL)
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
			argv = clear_arr(argv);
			res = clear_arr(res);
			return (werror("Error\n", 2));
		}
	}
	return (res);
}

void	pre_parse(int *argc, char ***argv)
{
	if (argc > 2)
		*argv = rm_el(*argv, 0, *argc);
	if (*argc == 2)
	{
		*argv == ft_split(*argv[1], ' ');
		*argc = ft_arrlen(*argv);
	}
	else
		*argv = NULL;
}

int		*transform(int argc, char **arr)
{
	int	*res;
	int	i;

	res = malloc((ft_arrlen(arr) + 1) * sizeof(int));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
	{
		res[i] = ft_atoi(arr[i]);
		if (res[i] == NULL)
		{
			clear_arr(res);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}
