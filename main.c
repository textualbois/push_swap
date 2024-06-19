/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:38:37 by isemin            #+#    #+#             */
/*   Updated: 2024/06/19 23:14:29 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*input;

	if (argc > 1)
	{
		input = parse_check(argc, argv);
		if (input != NULL)
		{
			if(no_duplicates(input))
				execute_push_swap(input);
			free(input);
		}
		else
		{
			werror("Error\n", 2);
			return (1);
		}
	}
	return (0);
}
