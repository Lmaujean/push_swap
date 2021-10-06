#include <stdio.h>
#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
    // int j;
    int i;
    int y;
    char    **tab;
    

    // j = 0;
    
    i = 0;
    (void) argc;
    while (argv[++i])
    {
        y = 0;
        tab = ft_split(argv[i], ' ');
        
        while (tab[y])
        {
            ft_atoi(tab[y]);
            y++;
        }
        if (ft_pars(tab))
            ft_putstr_fd("Error\n", 1);
    }
    return (0);
}