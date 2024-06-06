# include "push_swap.h"

void	execute_push_swap(int *inputs)
{
	t_stacknode	*a_head;
	t_stacknode	*b_head;
	int			best_dir;

	best_dir = 0;
	a_head = init_stack_a(inputs);
	//print_stack(a_head);
	b_head = NULL;
	if (a_head != NULL)
	{
		while (a_head != NULL)
			move_2_stack_b(&a_head, &b_head, best_dir);
		reset_order(&b_head);
	}
	else
		werror("Error\n", 2);
	//ft_putstr_fd("\n\nSENDING BACK TO B\n\n", 1);
	while (b_head != NULL)
		move_2_stack_a(&a_head, &b_head);
}

void	move_2_stack_a(t_stacknode **a_head, t_stacknode **b_head)
{
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
	// ft_putstr_fd("temp moves are - ", 1);
	// ft_putnbr_fd(min_moves, 1);
	// ft_putstr_fd("\n", 1);
	best_a_node = a_node;
	a_node = a_node->next;
	while (a_node != *a_head)
	{
		temp_dir = calculate_moves(a_node, *a_head, *b_head, &temp_moves);
		// ft_putstr_fd("temp moves are - ", 1);
		// ft_putnbr_fd(temp_moves, 1);
		// ft_putstr_fd("\n", 1);
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

void	do_a_2_b_movement(t_stacknode **a_head, t_stacknode **b_head, t_stacknode *a_node, int direction)
{
	t_twoints	pos;
	t_twoints	len;

	get_a_node_pos(&(pos.a), &(len.a), a_node, *a_head);
	get_b_node_insert(&(pos.b), &(len.b), a_node->value, *b_head);
	if (direction == both_up)
		move_both_up(a_head, b_head, pos);
	else if (direction == both_down)
		move_both_down(a_head, b_head, pos, len);
	else if (direction == a_up_b_down)
		move_a_up_b_down(a_head, b_head, pos, len);
	else
		move_a_down_b_up(a_head, b_head, pos, len);
	push(a_head, b_head);
	write(1, "pb\n", 3);
}

    // return (int_min(
    //                 int_min(
    //                         int_max(a_pos, b_pos),
    //                         int_max(a_len - a_pos + 1, b_len - b_pos + 1)),
    //                 int_min(
    //                         a_pos + b_len - b_pos + 1,
    //                         a_len - a_pos + 1 + b_pos)
    //                 )
    //         );
