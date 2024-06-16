/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:39:57 by isemin            #+#    #+#             */
/*   Updated: 2024/06/16 18:39:58 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		j = i + 1;
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
