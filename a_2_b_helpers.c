#include "push_swap.h"

int	calculate_moves(t_stacknode *a_node, t_stacknode *a_head, t_stacknode *b_head, int *moves)
{
	t_twoints	pos;
	t_twoints	len;
	int			res;

	get_a_node_pos(&(pos.a), &(len.a), a_node, a_head);
	get_b_node_insert(&(pos.b), &(len.b), a_node->value, b_head);
	*moves = int_max(pos.a, pos.b);
	res = both_up;
	if (int_max(len.a - pos.a + 1, len.b - pos.b + 1) < *moves)
	{
		*moves = int_max(len.a - pos.a + 1, len.b - pos.b + 1);
		res = both_down;
	}
	if ((pos.a + len.a - pos.b + 1) < *moves)
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

void	get_a_node_pos(int *pos, int *len, t_stacknode *node, t_stacknode *head)
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
	// ft_putstr_fd("\nfor value = ", 1);
	// ft_putnbr_fd(node->value, 1);
	// ft_putstr_fd(" - pos.a is = ", 1);
	// ft_putnbr_fd(*pos, 1);
}

void	get_b_node_insert(int *pos, int *len, int value, t_stacknode *head)
{
	t_stacknode	*current;
	//int			largest;
	int			got_pos;

	//largest = value;
	got_pos = false;
	*pos = 0;
	*len = 0;
	current = head;
	while (head != NULL && current->next != head)
	{
	//	largest = int_max(largest, current->value);
		if (value > current->value)
		{
			if (value < current->prev->value)
				got_pos = true;
		}
		*len = *len + 1;
		if (got_pos == false)
			*pos = *pos + 1;
		current = current->next;
	}
	if (got_pos == false)
		get_pos_alt(pos, head);
	// ft_putstr_fd(" - pos.b is = ", 1);
	// ft_putnbr_fd(*pos, 1);
	// ft_putstr_fd(" ", 1);
}

void	get_pos_alt(int *pos, t_stacknode *head)
{
	t_stacknode	*current;
	int			largest;
	int			index;

	index = 0;
	*pos = index;
	if (head != NULL)
	{
		largest = head->value; // = 1
		current = head->next; // n(6)
		while (current != head)
		{
			index++; // = 1
			if (current->value > largest) // 6 > 1 ? true
			{
				*pos = index; //pos = 1
				largest = current->value; // 6
			}
			current = current->next; // n(3)
		}
	}
}
