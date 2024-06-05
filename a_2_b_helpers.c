#include "push_swap.h"

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

void    get_a_node_pos(int *pos, int *len, t_stacknode *node, t_stacknode *head)
{
    t_stacknode *current; 

    *pos = 0;
    *len = 0;
    current = head;
    while (current->next != node)
    {
        (*pos)++;
        (*len)++;
        current = current->next;
    }
    while (current->next != head)
    {
        (*len)++;
        current = current->next;
    }
}

void    get_b_node_insert(int *pos, int *len, int value, t_stacknode *head)
{
    t_stacknode *current;
    int         smallest;
    int         got_pos;

    smallest = value;
    got_pos = false;
    *pos = 0;
    *len = 0;
    current = head;
    while (current->next != head && head != NULL)
    {
        smallest = int_min(smallest, current->value);
        if (value < current->value)
        {
            if (value > current->prev->value)
                got_pos = true;
        }
        (*len)++;
        if (got_pos == false)
            (*pos)++;
        current = current->next;
    }
    if (got_pos == false)
        get_pos_alt(pos, head);
}

void    get_pos_alt(int *pos, t_stacknode *head)
{
    t_stacknode *current;
    int         smallest;
    int         index;

    index = 0;
    *pos = index;
    smallest = head->value;
    current = head->next;
    if (head != NULL)
    {
        while (current != head)
        {
            index++;
            if (current->value < smallest)
            {
                *pos = index;
                smallest = current->value;
            }
        }
    }
}
