#include "push_swap.h"

void	print_stack(t_stacknode *head)
{
	t_stacknode	*temp;

	if (head == NULL)
		write(1, "stack NULL\n", ft_strlen("stack NULL\n"));
	else
	{
		temp = head;
		write(1, "stack start\n|", ft_strlen("stack start\n|"));
		ft_putnbr_fd(temp->value, 1);
		temp = temp->next;
		while (temp != head)
		{
			write(1, " ", 1);
			ft_putnbr_fd(temp->value, 1);
			temp = temp->next;
		}
		write(1, "|\n", 2);
		write(1, "stack end\n", ft_strlen("stack end\n"));
	}
}
