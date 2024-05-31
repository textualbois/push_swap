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
	int *res;

	pre_parse(&argc, &argv);
	if (argv == NULL)
		return (werror("Error\n", 2));
	res = transform(argc, argv);
	clear_arr(argv);
	return (res);
}

void	pre_parse(int *argc, char ***argv)
{
	if (*argc > 2)
		*argv = rm_el(*argv, 0, *argc);
	else if (*argc == 2)
	{
		*argv = ft_split((*argv)[1], ' ');
		*argc = ft_arrlen(*argv) + 1;
	}
	else
		*argv = NULL;
}

int	*transform(int argc, char **arr)
{
	int	*res;
	int	i;

	res = malloc((argc) * sizeof(int));
	if (res == NULL)
		return (NULL);
	res[0] = argc;
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
