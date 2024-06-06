#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*input;

	input = parse_check(argc, argv);
	if (input == NULL)
	{
		free(input); // dont need to free as it is freed in parse_check
	}
	else if (no_duplicates(input))
	{
		execute_push_swap(input);
	}
	else
		werror("Error\n", 2);
	free(input);
}
