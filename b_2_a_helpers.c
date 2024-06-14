#include "push_swap.h"

#include "push_swap.h"

int	calculate_moves_2_a(t_stacknode *b_node, t_stacknode *a_head, t_stacknode *b_head, int *moves)
{
	t_twoints	pos;
	t_twoints	len;
	int			res;

	get_b_node_pos(&(pos.b), &(len.b), b_node, b_head);
	get_a_node_insert(&(pos.a), &(len.a), b_node->value, a_head);
	*moves = int_max(pos.a, pos.b);
	res = both_up;
	if (int_max(len.a - pos.a + 1, len.b - pos.b + 1) < *moves)
	{
		*moves = int_max(len.a - pos.a + 1, len.b - pos.b + 1);
		res = both_down;
	}
	if ((pos.a + len.b - pos.b + 1) < *moves)
	{
		*moves = pos.a + len.b - pos.b + 1;
		res = a_up_b_down;
	}
	if ((len.a - pos.a + 1 + pos.b) < *moves)
	{
		*moves = len.a - pos.a + 1 + pos.b;
		res = a_down_b_up;
	}
	return (res);
}

void	get_b_node_pos(int *pos, int *len, t_stacknode *node, t_stacknode *head)
{
	t_stacknode	*current;

	*pos = 0;
	*len = 0;
	current = head;
	while (current != node)
	{
		*pos = *pos + 1;
		*len = *len + 1;
		current = current->next;
	}
	while (current->next != head)
	{
		*len = *len + 1;
		current = current->next;
	}
	// ft_putstr_fd("for value = ", 1);
	// ft_putnbr_fd(node->value, 1);
	// ft_putstr_fd(" - pos.b is = ", 1);
	// ft_putnbr_fd(*pos, 1);
	// ft_putstr_fd("; ", 1);
}

void	get_a_node_insert(int *pos, int *len, int value, t_stacknode *head)
{
	t_stacknode	*current;
	int			got_pos;

	got_pos = false;
	*pos = 0;
	*len = -1;
	current = head;
	if (head != NULL)
	{
		if (value < current->value)
		{
			// ft_putstr_fd("\nvalue = ", 1);
			// ft_putnbr_fd(value, 1);
			// ft_putstr_fd(" is less than ", 1);
			// ft_putnbr_fd(current->value, 1);
			// ft_putstr_fd("\n", 1);
			if (value > current->prev->value)
			{
				// ft_putstr_fd("and is more than ", 1);
				// ft_putnbr_fd(current->prev->value, 1);
				// ft_putstr_fd("\n", 1);
				got_pos = true;
			}
		}
		*len = *len + 1;
		if (got_pos == false)
			*pos = *pos + 1;

		current = current->next;
		while (current != head)
		{
			if (value < current->value)
			{
				// ft_putstr_fd("\nvalue = ", 1);
				// ft_putnbr_fd(value, 1);
				// ft_putstr_fd(" is less than ", 1);
				// ft_putnbr_fd(current->value, 1);
				// ft_putstr_fd("\n", 1);
				if (value > current->prev->value)
				{
					// ft_putstr_fd("and is more than ", 1);
					// ft_putnbr_fd(current->prev->value, 1);
					// ft_putstr_fd("\n", 1);
					got_pos = true;
				}
			}
			*len = *len + 1;
			if (got_pos == false)
				*pos = *pos + 1;
			current = current->next;
		}
	}
	if (got_pos == false)
		get_pos_alt_2_a(pos, head);
	// ft_putstr_fd(" - pos.a is = ", 1);
	// ft_putnbr_fd(*pos, 1);
	// ft_putstr_fd(" - len.a is = ", 1);
	// ft_putnbr_fd(*len, 1);
	// ft_putstr_fd("\n", 1);
}

void	get_pos_alt_2_a(int *pos, t_stacknode *head)
{
	t_stacknode	*current;
	int			smallest;
	int			index;


	// ft_putstr_fd(" alt pos ", 1);
	index = 0;
	*pos = index;
	if (head != NULL)
	{
		smallest = head->value; // = 3
		current = head->next; // n(4) - |3 4 5 6 2|
		while (current != head)
		{
			index++; // = 1
			if (current->value < smallest) // 4 < 3 ? true
			{
				*pos = index; //pos = 1
				smallest = current->value; // 2
			}
			current = current->next; // n(5) - |3 4 5 6 2|
		}
	}
}
