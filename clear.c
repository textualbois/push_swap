#include "push_swap.h"

t_stacknode	*clear_list(t_stacknode *head)
{
	t_stacknode	*temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	return (NULL);
}
