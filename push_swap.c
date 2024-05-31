# include "push_swap.h"

void    execute_push_swap(int *inputs)
{
    t_stacknode *a_head;
    t_stacknode *b_head;

    a_head = init_stack_a(inputs);
    werror("Error\n", 2);
    if (a_head != NULL)
    {
        b_head = NULL;
        while (a_head != NULL)
            move_2_stack_b(&a_head, &b_head);
    }
}

void    move_2_stack_b(t_stacknode **a_head, t_stacknode **b_head)
{
    t_stacknode *a_node;
    int         min_moves;
    int         temp_moves;
    t_stacknode *best_a_node;

    a_node = *a_head;
    min_moves = calculate_moves(a_node, *a_head, *b_head);
    best_a_node = a_node;
    a_node = a_node->next;
    while (a_node != *a_head)
    {
        temp_moves = calculate_moves(a_node, *a_head, *b_head);
        if (temp_moves < min_moves)
        {
            best_a_node = a_node;
            min_moves = temp_moves;
        }
        a_node = a_node->next;
    }
    do_a_2_b_movement(a_head, b_head, best_a_node);
}

// Todo
void do_a_2_b_movement(t_stacknode **a_head, t_stacknode **b_head, t_stacknode *best_a_node)
{
    if (best_a_node->prev)
        best_a_node->prev->next = best_a_node->next;
    if (best_a_node->next)
        best_a_node->next->prev = best_a_node->prev;

    // If best_a_node was the only node or the top node, update a_head
    if (best_a_node == *a_head) 
    {
        if (best_a_node->next != best_a_node)
            *a_head = best_a_node->next;
        else
            *a_head = NULL;
    }
    
    // Link best_a_node to the top of stack B
    if (*b_head)
    {
        best_a_node->next = *b_head;
        best_a_node->prev = (*b_head)->prev;
        (*b_head)->prev->next = best_a_node;
        (*b_head)->prev = best_a_node;
    }
    else
    {
        best_a_node->next = best_a_node;
        best_a_node->prev = best_a_node;
    }

    // Update best_a_node to be the new top of stack B
    *b_head = best_a_node;
    best_a_node->is_top = 1;
}

int calculate_moves(t_stacknode *a_node, t_stacknode *a_head, t_stacknode *b_head)
{
    int a_pos;
    int b_pos;
    int a_len;
    int b_len;
    
    get_a_node_pos(&a_pos, &a_len, a_node, a_head);
    get_b_node_insert(&b_pos, &b_len, a_node->value, b_head);
    return (int_min(
                int_min(
                    int_max(a_pos, b_pos),
                    int_max(a_len - a_pos + 1, b_len - b_pos + 1)),
                int_min(
                    a_pos + b_len-b_pos + 1,
                    a_len - a_pos + 1 + b_pos)
            ));
}
