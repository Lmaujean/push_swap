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

int		ft_isdoublon(int ac, char **tab)
{
	int i;

	i = 0;
	while (i < ac)
	{
		if (ft_atoi(tab[i]) == ft_atoi(tab[ac]))
			return (1);
		i++;
	}
	return (0);
}
	
int		ft_pars(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (ft_stringisdigit(tab[i]))
			return (1);
		if (ft_strissolong(tab[i]))
			return (1);
		if (ft_isdoublon(i, tab))
			return (1);
		i++;
	}
	return (0);
}

