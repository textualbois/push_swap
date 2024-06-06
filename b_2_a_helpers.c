#include "push_swap.h"

static void	get_largest_pos(int *to_top, int *to_bottom, t_stacknode *head)
{
	t_stacknode	*current;
	int			max;
	int			count;

	current = head;
	max = current->value;
	*to_top = 0;
	count = 0;
	current = current->next;
	while (current->value < max && current != head)
	{
		count++;
		current = current->next;
	}
	if (current->value > max)
	{
		*to_top = count;
		count = 0;
	}
	while (current != head)
	{
		count++;
		current = current->next;
	}
	*to_bottom = count;
}

void	reset_order(t_stacknode **head)
{
	int	to_top;
	int	to_bottom;

	// ft_putstr_fd("\nvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\nreseting stack b order\n", 1);
	// ft_putstr_fd("stack was :\n", 1);
	// print_stack(*head);
	get_largest_pos(&to_top, &to_bottom, *head);
	// write(1, "to_top = ", 9);
	// ft_putnbr_fd(to_top, 1);
	// write(1, "\n", 2);
	// write(1, "to_bottom = ", 12);
	// ft_putnbr_fd(to_bottom, 1);
	// write(1, "\n\n", 2);
	if (to_top <= to_bottom)
	{
		while (to_top != 0)
		{
			rev_rotate(head);
			to_top--;
			write(1, "rrb\n", 4);
		}
	}
	else
	{
		while (to_bottom >= 0)
		{
			rotate(head);
			to_bottom--;
			write(1, "rb\n", 3);
		}
	}
// 	ft_putstr_fd("\nstack became :\n", 1);
// 	print_stack(*head);
// 	ft_putstr_fd("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n", 1);
}
