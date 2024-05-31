#include "push_swap.h"

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
