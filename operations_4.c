#include "push_swap.h"

void	ss(t_stacknode **head_a, t_stacknode **head_b)
{
	swap_top(head_a);
	swap_top(head_b);
}

void	rr(t_stacknode **head_a, t_stacknode **head_b)
{
	rotate(head_a);
	rotate(head_b);
}

void	rev_rr(t_stacknode **head_a, t_stacknode **head_b)
{
	rev_rotate(head_a);
	rev_rotate(head_b);
}
