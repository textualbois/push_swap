#include "push_swap.h"

int	is_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int *parse_check(int argc, char **argv)
{
	int i;
	int *res;

	pre_parse(&argc, &argv);
	if (argv == NULL)
		return (werror("Error\n", 2));
	i = 0;
	res = transform(argc, argv);
	clear_arr(argv);
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
	res[0] = ft_arrlen(arr);
	i = 0;
	while (arr[i] != NULL)
	{
		if (is_int(arr[i]))
			res[i + 1] = ft_atoi(arr[i]);
		else
		{
			werror("Error\n", 2);
			free(res);
			return (NULL);
		}
		i++;
	}
	return (res);
}
