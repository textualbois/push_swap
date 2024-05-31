#include "push_swap.h"

int main (int argc, char **argv)
{
    int *input;
    int i = 0;

    input = parse_check(argc, argv);
    if (input == NULL)
    {
        free(input); // dont need to free as it is freed in parse_check
       // bad_input(); // error message is also in parse_check
    }
    else
    {
        while (i <= input[0])
        {
            printf("%i\n", input[i]);
            i++;
        }
        //exec_push_swap(input);
    }
    
}