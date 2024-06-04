#include "push_swap.h"

void	push(t_stacknode **src, t_stacknode **dst)
{
	t_stacknode	*src_new_head;
	t_stacknode *src_new_tail;
	
	src_new_head = (*src)->next;
	src_new_tail = (*src)->prev;
	insert_before(*dst, *src);
	make_circular(src_new_head, src_new_tail);
	(*dst)->is_top = 0;
	src_new_head->is_top = 1;
	*dst = *src;
	if (src_new_head != *src)
		*src = src_new_head;
	else
		*src = NULL;
}

void	swap_top(t_stacknode **head)
{
	t_stacknode *first;
	t_stacknode *second;

	if(head != NULL && *head != NULL && (*head)->next != head)
	{
		first = *head;
		second = first->next;
		first->prev->next = second; // 0->2
		second->prev = first->prev; // 0<-2 
		first->next = second->next; // 1->3
		second->next->prev = first; // 1<-3
		second->next = first; // 2->1
		first->prev = second; // 2<-1
		first->is_top = 0;
		second->is_top = 1;
		*head = second;
	}
}

void	rotate(t_stacknode **head)
{
	t_stacknode *first;

	first = *head;
	first->is_top = 0;
	first->next->is_top = 1;
	*head = first->next;
}

void	rev_rotate(t_stacknode **head)
{
	t_stacknode *first;

	first = *head;
	first->is_top = 0;
	first->prev->is_top = 1;
	*head = first->prev;
}


