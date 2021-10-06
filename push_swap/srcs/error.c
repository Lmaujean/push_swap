/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:11:29 by lmaujean          #+#    #+#             */
/*   Updated: 2021/09/29 17:11:33 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int    ft_stringisdigit(char *av)
{
    int i;

    i = 0;
	if (av[0] == '-' && ft_strlen(av) >= 2)
		i++;
    while (av[i])
    {
        if (!ft_isdigit(av[i]))
			return (1);
        i++;
    }
    return (0);
}

int     ft_strissolong(char *av)
{
	long long value;

	value = ft_atoi(av);
	if (ft_strlen(av) > 11)
		return (1);
	if (value < INT_MIN || value > INT_MAX)
		return (1);
	return (0);
}

int		ft_isdoublon(int ac, char **av)
{
	int i;

	i = 0;
	while (i < ac)
	{
		if (ft_atoi(av[i]) == ft_atoi(av[ac]))
			return (1);
		i++;
	}
	return (0);
}
	
int		ft_pars(char **av)
{
	int i;

	i = 0;
	while (av[i])
	{
		if (ft_stringisdigit(av[i]))
			return (1);
		if (ft_strissolong(av[i]))
			return (1);
		if (ft_isdoublon(i, av))
			return (1);
		i++;
	}
	return (0);
}

