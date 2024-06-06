#include "push_swap.h"

void	three_sort(t_stacknode **head)
{
	t_stacknode	*max_val;

	max_val = *head; // bad placeholder
	//max_val = max_value(*head);
	if (max_val == *head)
		rotate(head);
	if (max_val == (*head)->next)
		rev_rotate(head);
	if ((*head)->value > (*head)->next->value)
		swap_top(head);
}
