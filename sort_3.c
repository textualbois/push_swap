#include "push_swap.h"

void	three_sort(t_stacknode **head)
{
	t_stacknode	*max_node;

	max_node = ft_max_val_node(*head);
	if (max_node == *head)
	{
		rotate(head);
		ft_putstr_fd("ra\n", 1);
		// ft_putstr_fd("A = ", 1);
		// print_stack(*head);
	}
	if (max_node == (*head)->next)
	{
		rev_rotate(head);
		ft_putstr_fd("rra\n", 1);
		// ft_putstr_fd("A = ", 1);
		// print_stack(*head);
	}
	if ((*head)->value > (*head)->next->value)
	{
		swap_top(head);
		ft_putstr_fd("sa\n", 1);
		// ft_putstr_fd("A = ", 1);
		// print_stack(*head);
	}
}
