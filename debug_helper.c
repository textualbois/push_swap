/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:36:51 by isemin            #+#    #+#             */
/*   Updated: 2024/06/16 18:38:24 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stacknode *head)
{
	t_stacknode	*temp;

	if (head == NULL)
		write(1, "stack NULL\n", ft_strlen("stack NULL\n"));
	else
	{
		temp = head;
		write(1, "|", 1);
		ft_putnbr_fd(temp->value, 1);
		temp = temp->next;
		while (temp != head)
		{
			write(1, " ", 1);
			ft_putnbr_fd(temp->value, 1);
			temp = temp->next;
		}
		write(1, "|\n", 2);
	}
}
