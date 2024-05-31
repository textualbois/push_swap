#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdbool.h>
# include "libft/libft.h"

# define other_task_present 0

typedef struct s_stacknode{
    int                 is_top;
    int                 value;
    struct s_stacknode  *next;
    struct s_stacknode  *prev;
}   t_stacknode;

//a_2_b_helpers.c
void        get_a_node_pos(int *pos, int *len, t_stacknode *node, t_stacknode *head);
void        get_b_node_insert(int *pos, int *len, int value, t_stacknode *head);
void        get_pos_alt(int *pos, t_stacknode *head);

//arr_utils.c
size_t      ft_arrlen(char **arr);
void        *clear_arr(char **res_arr);
char        **rm_el(char **arr, int index, int arr_len);

//clear.c
t_stacknode *clear_list(t_stacknode *head);

//error.c
void	    *werror(char *msg, int fd);

//init.c
t_stacknode *init_stack_a(int *inputs);

//operations_1.c
t_stacknode *create_new_node(int value);
void	    make_circular(t_stacknode *head, t_stacknode *last);
void	    add_after(t_stacknode *current, t_stacknode *new);
void	    add_before(t_stacknode *current, t_stacknode *new);

//oporations_2.c
void	    insert_after(t_stacknode *current, t_stacknode *new);
void	    insert_before(t_stacknode *current, t_stacknode *new);

//parse_check.c
int         is_int(char *str);
int         *parse_check(int argc, char **argv);
void	    pre_parse(int *argc, char ***argv);
int		    *transform(int argc, char **arr);

//parse_check_2.c
int         no_duplicates(int *arr);


//push_swap.c
void        execute_push_swap(int *inputs);
void        move_2_stack_b(t_stacknode **a_head, t_stacknode **b_head);
void        do_a_2_b_movement(t_stacknode **a_head, t_stacknode **b_head, t_stacknode *best_a_node);
int         calculate_moves(t_stacknode *a_node, t_stacknode *a_head, t_stacknode *b_head);

//wild_math.c
int         int_min(int a, int b);
int         int_max(int a, int b);

#endif