#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdbool.h>
# include "libft/libft.h"

# define other_task_present 0

typedef struct s_stacknode{
    int         is_top;
    int         value;
    t_stacknode *next;
    t_stacknode *prev;
}	t_stacknode;

#endif