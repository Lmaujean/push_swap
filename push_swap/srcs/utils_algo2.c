/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:28:37 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/08 13:28:41 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void    ft_search_move(t_push *push, size_t n, void (*top)(), void (*bot)())
{
    void    (*f)();
    size_t len_stack;

    len_stack = push->stack_a->len;
    if (n < (len_stack / 2))
    {
        n = (len_stack - n + 1);
        f = bot;
    }
    else
    {
        n--;
        f = top;        
    }
    while (n--)
        (*f)(push);  
}
