/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:38:59 by isemin            #+#    #+#             */
/*   Updated: 2024/06/16 18:39:04 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_after(t_stacknode *dst, t_stacknode *new_node)
{
	if (dst != NULL)
	{
		add_before(dst->next, new_node);
		add_after(dst, new_node);
	}
}

void	insert_before(t_stacknode *dst, t_stacknode *new_node)
{
	if (dst != NULL)
	{
		add_after(dst->prev, new_node);
		add_before(dst, new_node);
	}
}
