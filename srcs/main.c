#include <stdio.h>
#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
    int j;
    int i;

    j = 0;
    i = 0;
    if (argc < 2 || ft_stringisdigit(argc, argv) || ft_strissolong(argc, argv))
        printf("%s\n", "Error");
    return (0);
}