/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:36:44 by isemin            #+#    #+#             */
/*   Updated: 2024/06/16 18:41:01 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacknode	*clear_list(t_stacknode *head)
{
	t_stacknode	*temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	return (NULL);
}
