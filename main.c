#include "push_swap.h"

int main (int argc, char **argv)
{
    int *input;

    input = parse_check(argc, argv);
    if (input == NULL)
    {
        free(input);
        bad_input();
    }
    else
    {
        exec_push_swap(input);
    }
    
}