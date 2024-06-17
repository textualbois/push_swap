/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:40:00 by isemin            #+#    #+#             */
/*   Updated: 2024/06/17 17:22:57 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	*parse_check(int argc, char **argv)
{
	int		*res;
	char	**temp;

	temp = NULL;
	pre_parse(&argc, &argv, &temp);
	if (temp == NULL)
		return (NULL);
	res = transform(argc, temp);
	clear_arr(temp);
	return (res);
}

void	pre_parse(int *argc, char ***argv, char ***temp)
{
	if (*argc > 2)
		*temp = rm_el(*argv, 0, *argc);
	else if (*argc == 2)
	{
		*temp = ft_split((*argv)[1], ' ');
		*argc = ft_arrlen(*temp) + 1;
	}
	else
		*temp = NULL;
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
			free(res);
			return (NULL);
		}
		i++;
	}
	return (res);
}
