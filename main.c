#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*input;

	input = parse_check(argc, argv);
	if (input != NULL && no_duplicates(input))
	{
		execute_push_swap(input);
		free(input);
	}
	else
		werror("Error\n", 2);
}
