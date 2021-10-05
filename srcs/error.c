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

int    ft_stringisdigit(int ac, char **av)
{
    int i;
    int j;

    j = 1;
    while (j < ac)
    {
        i = 0;
        while (av[j][i])
        {
            if (!ft_isdigit(av[j][i]) && !ft_isdigit(av[j][i + 1]))
            	return (1);
        	i++;
        }
    	j++;
    }
    return (0);
}

int     ft_strissolong(int ac, char **av)
{
	long long value;
	int j;
	int i;

	j = 1;
	i = 0;
	value = ft_atoi(&av[j][i]);
	while (j < ac)
	{
		if (value < INT_MIN || value > INT_MAX)
			return (1);
		j++;
	}
	return (0);
}