# include "push_swap.h"

void    execute_push_swap(int *inputs)
{
    t_stacknode *a_head;
    t_stacknode *b_head;

    a_head = init_stack_a(inputs);
    if (a_head == NULL)
        return (NULL);
    b_head = NULL;
    while (a_head != NULL)
        move_2_stack_b(a_head, *b_head)


}