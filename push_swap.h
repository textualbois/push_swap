/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:40:17 by isemin            #+#    #+#             */
/*   Updated: 2024/06/19 15:02:32 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdbool.h>
# include "libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define BOTH_UP 0
# define BOTH_DOWN 1
# define A_UP_B_DOWN 2
# define A_DOWN_B_UP 3
# define KO 2
# define ERROR 1
# define OK 0
# define CMD_NOT_MATCHED 1
# ifndef MIN_INT
#  define MIN_INT -2147483648
# endif
# ifndef MAX_INT
#  define MAX_INT 2147483647
# endif

typedef struct s_twoints{
	int			a;
	int			b;
}				t_twoints;

typedef struct s_stacknode{
	int					is_top;
	int					value;
	struct s_stacknode	*next;
	struct s_stacknode	*prev;
}						t_stacknode;

//a_2_b_helpers.c
void		get_a_node_pos(int *pos, int *len, t_stacknode *node, \
							t_stacknode *head);
void		get_b_node_insert(int *pos, int *len, int value, t_stacknode *head);
void		get_pos_alt(int *pos, t_stacknode *head);
int			calculate_moves(t_stacknode *a_node, t_stacknode *a_head, \
							t_stacknode *b_head, int *moves);

//arr_utils.c
size_t		ft_arrlen(char **arr);
void		*clear_arr(char **res_arr);
char		**rm_el(char **arr, int index, int arr_len);

//list_utuls.c
int			ft_stacksize(t_stacknode *head);
t_stacknode	*ft_max_val_node(t_stacknode *head);

//b_2_a_helpers.c
int			calculate_moves_2_a(t_stacknode *b_node, t_stacknode *a_head, \
								t_stacknode *b_head, int *moves);
void		get_b_node_pos(int *pos, int *len, t_stacknode *node, \
							t_stacknode *head);
void		get_a_node_insert(int *pos, int *len, int value, t_stacknode *head);
void		get_pos_alt_2_a(int *pos, t_stacknode *head);

//fix_order.c
void		reset_order_a(t_stacknode **head);
void		reset_order_b(t_stacknode **head);

//get_next_line.c
char		*get_next_line(int fd);

//clear.c
t_stacknode	*clear_list(t_stacknode *head);
void		*free_return(void *arg);

//error.c
void		*werror(char *msg, int fd);

//init.c
t_stacknode	*init_stack_a(int *inputs);

//operations_1.c
t_stacknode	*create_new_node(int value);
void		make_circular(t_stacknode *head, t_stacknode *last);
void		add_after(t_stacknode *current, t_stacknode *new);
void		add_before(t_stacknode *current, t_stacknode *new);

//oporations_2.c
void		insert_after(t_stacknode *dst, t_stacknode *new_node);
void		insert_before(t_stacknode *dst, t_stacknode *new_node);

//operations_3.c
void		push(t_stacknode **src, t_stacknode **dst);
void		swap_top(t_stacknode **head);
void		rotate(t_stacknode **head);
void		rev_rotate(t_stacknode **head);

//operations_4.c
void		ss(t_stacknode **head_a, t_stacknode **head_b);
void		rr(t_stacknode **head_a, t_stacknode **head_b);
void		rev_rr(t_stacknode **head_a, t_stacknode **head_b);

//parse_check.c
int			is_int(char *str);
int			*parse_check(int argc, char **argv);
void		pre_parse(int *argc, char ***argv, char ***temp);
int			*transform(int argc, char **arr);

//parse_check_2.c
int			no_duplicates(int *arr);
int			check_if_sorted(t_stacknode **stack_a);

//push_swap.c
void		execute_push_swap(int *inputs);
void		move_2_stack_b(t_stacknode **a_head, \
							t_stacknode **b_head, int best_dir);
void		do_a_2_b_movement(t_stacknode **a_head, t_stacknode **b_head, \
								t_stacknode *a_node, int direction);
void		move_2_stack_a(t_stacknode **a_head, \
							t_stacknode **b_head, int best_dir);
void		do_b_2_a_movement(t_stacknode **a_head, t_stacknode **b_head, \
								t_stacknode *a_node, int direction);

//sort_3.c
void		three_sort(t_stacknode **head);

//cmd_executer.c
void		move_both_up(t_stacknode **a_head, t_stacknode **b_head, \
							t_twoints pos);
void		move_both_down(t_stacknode **a_head, t_stacknode **b_head, \
							t_twoints pos, t_twoints len);
void		move_a_up_b_down(t_stacknode **a_head, t_stacknode **b_head, \
							t_twoints pos, t_twoints len);
void		move_a_down_b_up(t_stacknode **a_head, t_stacknode **b_head, \
							t_twoints pos, t_twoints len);

//wild_math.c
int			int_min(int a, int b);
int			int_max(int a, int b);

//debug_helper.c
void		print_stack(t_stacknode *head);

//a_2_b_b_2_a_helper_helpers.c
void		check_b_insert_pos(int a_val, int val_bellow, \
								int val_above, int *got_pos);
void		check_a_insert_pos(int b_val, int val_bellow, \
								int val_above, int *got_pos);
t_stacknode	*increment_all(int *pos, int *len, int got_pos, \
							t_stacknode *current_node);

#endif