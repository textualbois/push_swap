/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:40:14 by isemin            #+#    #+#             */
/*   Updated: 2024/06/17 17:08:58 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_push_swap(int *inputs)
{
	t_stacknode	*a_head;
	t_stacknode	*b_head;
	int			best_dir;

	best_dir = 0;
	a_head = init_stack_a(inputs);
	b_head = NULL;
	if (a_head != NULL)
	{
		while (ft_stacksize(a_head) > 3)
			move_2_stack_b(&a_head, &b_head, best_dir);
		three_sort(&a_head);
		while (b_head != NULL)
			move_2_stack_a(&a_head, &b_head, best_dir);
		reset_order_a(&a_head);
		clear_list(a_head);
	}
	else
		werror("Error\n", 2);
}

void	move_2_stack_a(t_stacknode **a_head, t_stacknode **b_head, int best_dir)
{
	t_stacknode	*b_node;
	int			min_moves;
	int			temp_moves;
	t_stacknode	*best_b_node;
	int			temp_dir;

	temp_dir = best_dir;
	b_node = *b_head;
	best_dir = calculate_moves_2_a(b_node, *a_head, *b_head, &min_moves);
	best_b_node = b_node;
	b_node = b_node->next;
	while (b_node != *b_head)
	{
		temp_dir = calculate_moves_2_a(b_node, *a_head, *b_head, &temp_moves);
		if (temp_moves < min_moves)
		{
			best_b_node = b_node;
			min_moves = temp_moves;
			best_dir = temp_dir;
		}
		b_node = b_node->next;
	}
	do_b_2_a_movement(a_head, b_head, best_b_node, best_dir);
}

void	do_b_2_a_movement(t_stacknode **a_head, t_stacknode **b_head, \
							t_stacknode *b_node, int direction)
{
	t_twoints	pos;
	t_twoints	len;

	get_b_node_pos(&(pos.b), &(len.b), b_node, *b_head);
	get_a_node_insert(&(pos.a), &(len.a), b_node->value, *a_head);
	if (direction == BOTH_UP)
		move_both_up(a_head, b_head, pos);
	else if (direction == BOTH_DOWN)
		move_both_down(a_head, b_head, pos, len);
	else if (direction == A_UP_B_DOWN)
		move_a_up_b_down(a_head, b_head, pos, len);
	else
		move_a_down_b_up(a_head, b_head, pos, len);
	push(b_head, a_head);
	write(1, "pa\n", 3);
}

void	move_2_stack_b(t_stacknode **a_head, t_stacknode **b_head, int best_dir)
{
	t_stacknode	*a_node;
	int			min_moves;
	int			temp_moves;
	t_stacknode	*best_a_node;
	int			temp_dir;

	temp_dir = best_dir;
	a_node = *a_head;
	best_dir = calculate_moves(a_node, *a_head, *b_head, &min_moves);
	best_a_node = a_node;
	a_node = a_node->next;
	while (a_node != *a_head)
	{
		temp_dir = calculate_moves(a_node, *a_head, *b_head, &temp_moves);
		if (temp_moves < min_moves)
		{
			best_a_node = a_node;
			min_moves = temp_moves;
			best_dir = temp_dir;
		}
		a_node = a_node->next;
	}
	do_a_2_b_movement(a_head, b_head, best_a_node, best_dir);
}

void	do_a_2_b_movement(t_stacknode **a_head, t_stacknode **b_head, \
							t_stacknode *a_node, int direction)
{
	t_twoints	pos;
	t_twoints	len;

	get_a_node_pos(&(pos.a), &(len.a), a_node, *a_head);
	get_b_node_insert(&(pos.b), &(len.b), a_node->value, *b_head);
	if (direction == BOTH_UP)
		move_both_up(a_head, b_head, pos);
	else if (direction == BOTH_DOWN)
		move_both_down(a_head, b_head, pos, len);
	else if (direction == A_UP_B_DOWN)
		move_a_up_b_down(a_head, b_head, pos, len);
	else
		move_a_down_b_up(a_head, b_head, pos, len);
	push(a_head, b_head);
	write(1, "pb\n", 3);
}
