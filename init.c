#include "push_swap.h"

t_stacknode *init_stack_a(int *inputs)
{
	t_stacknode *head;
	t_stacknode *current;
	t_stacknode *new;
	int i;

	head = create_new_node(inputs[0]);
	if (head == NULL)
		return (NULL);
	head->is_top = 1;
	current = head;
	i = 1;
	while (inputs[i] != NULL)
	{
		new = create_new_node(inputs[i]);
		if (new == NULL)
			return (clear_list(head));
		add_after(current, new);
		i++;
		current = new;
	}
	make_circular(head, current);
	return (head);
}
