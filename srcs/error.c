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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

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
    int i;
    int j;

    j = 1;
    while (j < ac)
    {
        i = 0;
        while (av[j][i])
        {
            while (i)
            {
                if (i > INT_MAX || i < INT_MIN)
                    return (1);
            }
            i++;
        }
        j++;
    }
    return (0);
}