#include "push_swap.h"

void	move_both_up(t_stacknode **a_head, t_stacknode **b_head, t_twoints pos)
{
	while (pos.a != 0 && pos.b != 0)
	{
		rr(a_head, b_head);
		pos.a--;
		pos.b--;
		write(1, "rr\n", 4);
	}
	while (pos.a != 0)
	{
		rotate(a_head);
		pos.a--;
		write(1, "ra\n", 3);
	}
	while (pos.b != 0)
	{
		rotate(b_head);
		pos.b--;
		write(1, "rb\n", 3);
	}
}

void	move_both_down(t_stacknode **a_head, t_stacknode **b_head, t_twoints pos, t_twoints len)
{
	while (pos.a != len.a && pos.b != len.b)
	{
		rev_rr(a_head, b_head);
		pos.a++;
		pos.b++;
		write(1, "rrr\n", 4);
	}
	while (pos.a != len.a)
	{
		rev_rotate(a_head);
		pos.a++;
		write(1, "rra\n", 3);
	}
	while (pos.b != len.b)
	{
		rev_rotate(b_head);
		pos.b++;
		write(1, "rrb\n", 3);
	}
	rev_rr(a_head, b_head);
	write(1, "rrr\n", 4);
}

void	move_a_up_b_down(t_stacknode **a_head, t_stacknode **b_head, t_twoints pos, t_twoints len)
{
	while (pos.a != 0)
	{
		rotate(a_head);
		pos.a--;
		write(1, "ra\n", 3);
	}
	while (pos.b <= len.b)
	{
		rev_rotate(b_head);
		pos.b++;
		write(1, "rrb\n", 3);
	}
}

void	move_a_down_b_up(t_stacknode **a_head, t_stacknode **b_head, t_twoints pos, t_twoints len)
{
	while (pos.a <= len.a)
	{
		rev_rotate(a_head);
		pos.a++;
		write(1, "rra\n", 3);
	}
	while (pos.b != 0)
	{
		rotate(b_head);
		pos.b++;
		write(1, "rb\n", 3);
	}
}
