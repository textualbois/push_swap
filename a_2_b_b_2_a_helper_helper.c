/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_2_b_b_2_a_helper_helper.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:04:52 by isemin            #+#    #+#             */
/*   Updated: 2024/06/17 15:46:38 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_b_insert_pos(int a_val, int val_bellow, \
							int val_above, int *got_pos)
{
	if (a_val > val_bellow && a_val < val_above)
		*got_pos = true;
}

void	check_a_insert_pos(int b_val, int val_bellow, \
						int val_above, int *got_pos)
{
	if (b_val < val_bellow && b_val > val_above)
		*got_pos = true;
}

t_stacknode	*increment_all(int *pos, int *len, int got_pos, \
							t_stacknode *current_node)
{
	*len = *len + 1;
	if (!got_pos)
		*pos = *pos + 1;
	return (current_node->next);
}
