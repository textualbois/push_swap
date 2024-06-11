#include "push_swap.h"

int	ft_stacksize(t_stacknode *head)
{
	int			i;
	t_stacknode	*temp;

	temp = head->next;
	i = 1;
	while (temp != head)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

t_stacknode	*ft_max_val_node(t_stacknode *head)
{
	int			max_val;
	t_stacknode	*temp;
	t_stacknode	*max_node;

	max_val = head->value;
	max_node = head;
	temp = head->next;
	while (temp != head)
	{
		if (temp->value > max_val)
		{
			max_node = temp;
			max_val = max_node->value;
		}
		temp = temp->next;
	}
	return (max_node);
}
