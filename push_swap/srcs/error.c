#include "../includes/push_swap.h"

int    ft_stringisdigit(char *tab)
{
    int i;

    i = 0;
	if (tab[0] == '-' && ft_strlen(tab) >= 2)
		i++;
    while (tab[i])
    {
        if (!ft_isdigit(tab[i]))
			return (1);
        i++;
    }
    return (0);
}

int     ft_strissolong(char *tab)
{
	long long value;

	value = ft_atoi(tab);
	if (ft_strlen(tab) > 11)
		return (1);
	if (value < INT_MIN || value > INT_MAX)
		return (1);
	return (0);
}

int		ft_isdoublon(t_stack *stack)
{
	t_list *i;
	t_list *temp;

	i = stack->start;
	while (i != NULL)
	{
		temp = i->next;
		if (temp == NULL)
		{
			if (temp->value < i->value)
				return (1);
		}
		i = i->next;
	}
	return (0);
}
	
int		ft_pars(char **tab)
{
	int i;
	t_push *push;

	push = NULL;
	i = 0;
	while (tab[i])
	{
		if (ft_stringisdigit(tab[i]))
			return (1);
		if (ft_strissolong(tab[i]))
			return (1);
		if (ft_isdoublon(push->stack_a))
			return (1);
		i++;
	}
	return (0);
}
