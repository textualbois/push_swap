#include "push_swap.h"

static void	get_largest_pos(int *to_top, int *to_bottom, t_stacknode *head)
{
	t_stacknode	*current;
	int			max;
	int			count;

	current = head;
	max = current->value;
	*to_top = 0;
	count = 0;
	current = current->next;
	while (current->value < max && current != head)
	{
		count++;
		current = current->next;
	}
	if (current->value > max)
	{
		*to_top = count;
		count = 0;
	}
	while (current != head)
	{
		count++;
		current = current->next;
	}
	*to_bottom = count;
}

void	reset_order(t_stacknode **head)
{
	int	to_top;
	int	to_bottom;

	// ft_putstr_fd("\nvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\nreseting stack b order\n", 1);
	// ft_putstr_fd("stack was :\n", 1);
	// //print_stack(*head);
	get_largest_pos(&to_top, &to_bottom, *head);
	// write(1, "to_top = ", 9);
	// ft_putnbr_fd(to_top, 1);
	// write(1, "\n", 2);
	// write(1, "to_bottom = ", 12);
	// ft_putnbr_fd(to_bottom, 1);
	// write(1, "\n\n", 2);
	if (to_top <= to_bottom)
	{
		while (to_top >= 0)
		{
			rotate(head);
			to_top--;
			write(1, "rb\n", 3);
			//ft_putstr_fd("B = ", 1);
			//print_stack(*head);
		}
	}
	else
	{
		while (to_bottom >= 1)
		{
			rev_rotate(head);
			to_bottom--;
			write(1, "rrb\n", 4);
			//ft_putstr_fd("B = ", 1);
			//print_stack(*head);
		}
	}
	// ft_putstr_fd("\nstack became :\n", 1);
	// //print_stack(*head);
	// ft_putstr_fd("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n", 1);
}
// 135 917 150 751 182 417 291 175 92 424 615 10
// 00 245 486 393 572 957 519 225 648 642 605 786
// 718 83 874 53 990 168 149 466 382 96 187 582 67
// 100 561 476 535 328 11 848 857 538 711 404 747 2
// 78 127 464 131 904 908 920 554 547 195 619 773 29
// 470 344 626 321 564 837 422 332 657 152 988 949 971
// 437 533 716 397 246 800
// 794 514 569 270 31 670 474 868 846 932 930 861
// 430 613 956 488 712 618 154 257
// 135 917 150 751 182 417 291 175 92 424 615 1000 245 486 393 572 957 519 225 648 642 605 786 718 83 874 53 990 168 149 466 382 96 187 582 67 100 561 476 535 328 11 848 857 538 711 404 747 278 127 464 131 904 908 920 554 547 195 619 773 29 470 344 626 321 564 837 422 332 657 152 988 949 971 437 533 716 397 246 800 794 514 569 270 31 670 474 868 846 932 930 861 430 613 956 488 712 618 154 257
// ``` &#8203;:citation[oaicite:0]{index=0}&#8203;

// |291 182 150 135 917 751 417|
// rb <-
// rb <-
// |150 135 917 751 417 291 182|
// |175 150 135 917 751 417 291 182|

// rrb ->
// rrr ->

// |291 182 175 150 135 917 751 417|
// |257 291 182 175 150 135 917 751 417|

// |404 397 393 382 344 332 328 321 291 278 270 257 246 245 225 195 187 182
//  175 168 154 152 150 149 135 131 127 100 96 92 83 67 53 31 29 11 1000 990
//   988 971 957 956 949 932 930 920 917 908 904 874 868 861 857 848 846 837
//    800 794 786 773 751 747 718 716 712 711 670 657 648 642 626 619 618 615
//     613 605 582 572 569 564 561 554 
// 547 538 535 533 519 514 488 486 476 474 470 466 464 437 430 424 422 417|

// |712 711 670 657 648 642 626 619 618 615 613 605 582 572 569 564 561 554 
// 547 538 535 533 519 514 488 486 476 474 470 466 464 437 430 424 422 417 404 
// 397 393 382 344 332 328 321 291 278 270 257 246 245 225 195 187 182 175 168
//  154 152 150 149 135 131 127 100 96 92 83 67 53 31 29 11 1000 990 988 971 957 
//  956 949 932 930 920 917 908 904 874 868 861 857 848 846 837 800 794 786 773 751 747 718 716|