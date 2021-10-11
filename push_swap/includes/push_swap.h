/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:02:20 by lmaujean          #+#    #+#             */
/*   Updated: 2021/09/29 14:02:26 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>

typedef struct  s_list
{
    int         value;
    struct s_list *next;
    struct s_list *back;
}               t_list;

typedef struct  s_stack
{
    int         len;
    struct s_list *start;
    struct s_list *end;
}               t_stack;

typedef struct  s_push
{
    t_stack stack_a;
    t_stack stack_b;
}               t_push;

int			ft_stringisdigit(char *tab);
int			ft_strissolong(char *tab);
long long	ft_atoi(const char *nptr);
int			ft_isdigit(int c);
void        ft_putstr_fd(char *s, int fd);
size_t      ft_strlen(const char *s);
int	        ft_isdoublon(int ac, char **tab);
int		    ft_pars(char **tab);
char	    **ft_split(char *s, char c);
//void        check_error(char **lst);

#endif
