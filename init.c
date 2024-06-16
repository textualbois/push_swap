/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:37:45 by isemin            #+#    #+#             */
/*   Updated: 2024/06/16 18:38:21 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacknode	*init_stack_a(int *inputs)
{
	t_stacknode	*head;
	t_stacknode	*current;
	t_stacknode	*new;
	int			i;

	head = create_new_node(inputs[1]);
	if (head == NULL)
		return (NULL);
	head->is_top = 1;
	current = head;
	i = 2;
	while (i < inputs[0])
	{
		new = create_new_node(inputs[i]);
		if (new == NULL)
			return (clear_list(head));
		add_after(current, new);
		i++;
		current = new;
	}
	make_circular(head, current);
	return (head);
}
