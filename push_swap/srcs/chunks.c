/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:11:45 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/08 14:11:46 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int ft_chunk_bool(t_chunks *chunks, t_push *push)
{
    if (push->stack_a->start->value >= chunks->min &&
        push->stack_a->start->value <= chunks->max)
        return (1);
    return (0);
}

void    ft_push_chunk_to_b(t_push *push, t_chunks *chunks)
{
    int chunkmin;
    int chunkmax;
    
    chunkmin = ft_get_index_min(push->stack_a);
    chunkmax = chunkmin + 50;
    while (push->stack_a->len > 0)
    {
        if (ft_chunk_bool(chunks, push))
            ft_pb(push);
    }
}