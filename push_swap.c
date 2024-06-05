# include "push_swap.h"

void    execute_push_swap(int *inputs)
{
    t_stacknode *a_head;
    t_stacknode *b_head;
    int         best_dir;
    int         temp_dir;

    best_dir = 0;
    temp_dir = 0;
    a_head = init_stack_a(inputs);
    if (a_head != NULL)
    {
        b_head = NULL;
        while (a_head != NULL)
            move_2_stack_b(&a_head, &b_head, best_dir, temp_dir);
    }
    else
        werror("Error\n", 2);
}

void    move_2_stack_b(t_stacknode **a_head, t_stacknode **b_head, int best_dir, int temp_dir)
{
    t_stacknode *a_node;
    int         min_moves;
    int         temp_moves;
    t_stacknode *best_a_node;

    a_node = *a_head;
    best_dir = calculate_moves(a_node, *a_head, *b_head, &min_moves);
    best_a_node = a_node;
    a_node = a_node->next;
    while (a_node != *a_head)
    {
        temp_dir = calculate_moves(a_node, *a_head, *b_head, &temp_moves);
        if (temp_moves < min_moves)
        {
            best_a_node = a_node;
            min_moves = temp_moves;
        }
        a_node = a_node->next;
    }
    do_a_2_b_movement(a_head, b_head, best_a_node, best_dir);
}

// Todo
void do_a_2_b_movement(t_stacknode **a_head, t_stacknode **b_head, t_stacknode *a_node, int direction)
{
    t_twoints pos;
    t_twoints len;

    get_a_node_pos((&pos)->a, (&len)->a, a_node, *a_head);
    get_b_node_insert((&pos)->b, (&len)->b, a_node->value, *b_head);
    if (direction == both_up)
        move_both_up(a_head, b_head, pos);
    else if (direction == both_down)
        move_both_down(a_head, b_head, pos, len);
    else if (direction == a_up_b_down)
        move_a_up_b_down(a_head, b_head, pos, len);
    else
        move_a_down_b_up(a_head, b_head, pos, len);
    push(a_head, b_head);
    write(1, "pb\n", 3);
}

int calculate_moves(t_stacknode *a_node, t_stacknode *a_head, t_stacknode *b_head, int *moves)
{
    t_twoints pos;
    t_twoints len;
    int res;
    
    get_a_node_pos((&pos)->a, (&len)->a, a_node, a_head);
    get_b_node_insert((&pos)->b, (&len)->b, a_node->value, b_head);
    *moves = int_max(pos.a, pos.b);
    res = both_up;
    if (int_max(len.a - pos.a + 1, len.b - pos.b + 1) < moves)
    {
        *moves = int_max(len.a - pos.a + 1, len.b - pos.b + 1);
        res = both_down;
    }
    if ((pos.a + len.a - pos.b + 1) < moves)
    {
        *moves = pos.a + len.b - pos.b + 1;
        res = a_up_b_down;
    }
    if ((len.a - pos.a + 1 + pos.b) < moves)
    {
        *moves = len.a - pos.a + 1 + pos.b;
        res = a_down_b_up;
    }
    return (res);
}

    // return (int_min(
    //                 int_min(
    //                         int_max(a_pos, b_pos),
    //                         int_max(a_len - a_pos + 1, b_len - b_pos + 1)),
    //                 int_min(
    //                         a_pos + b_len - b_pos + 1,
    //                         a_len - a_pos + 1 + b_pos)
    //                 )
    //         );
