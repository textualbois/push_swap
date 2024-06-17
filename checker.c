/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:36:43 by isemin            #+#    #+#             */
/*   Updated: 2024/06/17 17:17:55 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	checker_output(t_stacknode **stack_a, \
						t_stacknode **stack_b, int output)
{
	(void) stack_a;
	(void) stack_b;
	if (output == OK)
	{
		ft_putstr_fd("OK\n", 1);
		exit(0);
	}
	if (output == ERROR)
		ft_putstr_fd("Error\n", 2);
	else if (output == KO)
		ft_putstr_fd("KO\n", 1);
	exit(1);
}

static void	check_if_sorted(t_stacknode **stack_a, t_stacknode **stack_b)
{
	t_stacknode	*temp;

	if (*stack_b)
		checker_output(stack_a, stack_b, KO);
	temp = (*stack_a)->next;
	if (temp->value < (*stack_a)->value)
		checker_output(stack_a, stack_b, KO);
	while (temp != *stack_a)
	{
		if (temp->value < temp->prev->value)
			checker_output(stack_a, stack_b, KO);
		temp = temp->next;
	}
	checker_output(stack_a, stack_b, 0);
}

static int	cmd_router(char *str, t_stacknode **stack_a, t_stacknode **stack_b)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		swap_top(stack_a);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		swap_top(stack_b);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		push(stack_b, stack_a);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		push(stack_a, stack_b);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		rotate(stack_a);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rotate(stack_b);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rr(stack_a, stack_b);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rev_rotate(stack_a);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rev_rotate(stack_b);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		rev_rr(stack_a, stack_b);
	else
		return (1);
	return (0);
}

static void	read_exec_loop(t_stacknode **stack_a, t_stacknode **stack_b)
{
	char	*str;
	int		i;

	i = -1;
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		i = cmd_router(str, stack_a, stack_b);
		free(str);
		if (i == CMD_NOT_MATCHED)
		{
			ft_putstr_fd("didn't match a cmd\n", 1);
			get_next_line(-1);
			checker_output(stack_a, stack_b, ERROR);
		}
	}
}

int	main(int argc, char **argv)
{
	t_stacknode	*stack_a;
	t_stacknode	*stack_b;
	int			*input;

	if (argc == 1)
		return (0);
	input = parse_check(argc, argv);
	if (input != NULL && no_duplicates(input))
	{
		stack_a = init_stack_a(input);
		free(input);
		stack_b = NULL;
		read_exec_loop(&stack_a, &stack_b);
		check_if_sorted(&stack_a, &stack_b);
	}
}
