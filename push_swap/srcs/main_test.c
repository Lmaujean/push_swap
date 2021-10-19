#include "../includes/push_swap.h"

int	ft_stack_empty(t_stack *stack)
{
	if (!stack)
		return (1);
	return (0);
}

t_list		*ft_new_dlist(int content)
{
	t_list *new_dlist;

	new_dlist = malloc(sizeof(*new_dlist));
	if (new_dlist == NULL)
		return (NULL);
	new_dlist->value = content;
	new_dlist->next = NULL;
	new_dlist->back = NULL;
	return(new_dlist);
}

t_stack		*ft_new_stack(int content)
{
	t_list *new_dlist;
	t_stack *new_stack;

	new_stack = malloc(sizeof(*new_stack));
	new_dlist = ft_new_dlist(content);
	if (new_dlist == NULL && new_stack == NULL)
		return (NULL);
	new_stack->len = 1;
	new_stack->start = new_dlist;
	new_stack->end = new_dlist;
	return (new_stack);
}

t_stack		*ft_stack_addback(t_stack *stack, int content)
{
	t_list *list;

    if (ft_stack_empty(stack))
    {
		stack = ft_new_stack(content);
		return (stack);
    }
	list = ft_new_dlist(content);
	if (list == NULL)
		return (NULL);
	stack->end->next = list;
	list->back = stack->end;
	stack->end = list;
	return (stack);
}

t_stack		*ft_stack_addfront(t_stack *stack, int content)
{
	t_list	*list;

	if (ft_stack_empty(stack))
	{
		stack = ft_new_stack(content);
		return (stack);
	}
	list = ft_new_dlist(content);
	if (list == NULL)
		return (NULL);
	stack->start->back = list;
	list->next = stack->start;
	stack->start = list;
	return (stack);
}

t_stack		*ft_stack_delback(t_stack *stack)
{
	t_list	*temp;

	if (ft_stack_empty(stack))
		return (NULL);
	if (stack->start == stack->end)
	{
		free(stack->end);
		stack->end = NULL; 
		free(stack);
		stack = NULL;
		return (stack);
	}
	temp = stack->end;
	stack->end = stack->end->back;
	stack->end->next = NULL;
	free(temp);
	temp = NULL;
	stack->len--;
	return (stack);
}

t_stack		*ft_stack_delfront(t_stack	*stack)
{
	t_list *temp;

	if (ft_stack_empty(stack))
		return (NULL);
	if (stack->start == stack->end)
	{
		free(stack->start);
		stack->start = NULL;
		free(stack);
		stack = NULL;
		return (stack);
	}
	temp = stack->start;
	stack->start = stack->start->next;
	stack->start->back = NULL;
	free(temp);
	temp = NULL;
	stack->len--;
	return (stack);
}

t_stack		*ft_clear_stack(t_stack *stack)
{
	while (stack)
		stack = ft_stack_delback(stack);
	return (stack);
}


void	print_list(t_stack *stack)
{
	t_list *tmp;

	if (ft_stack_empty(stack))
	{
		printf("La stack est vide\n");
		return;
	}
	tmp = stack->start;
	while (tmp)
	{
		printf("[%d] \n", tmp->value);
		tmp = tmp->next;
	}
}

int		ft_reverse_stack(t_stack *stack)
{
	t_list 	*temp;
	int			cpy;

	if (ft_stack_empty(stack))
		return (1);
	if (stack->start == stack->end)
		return (1);
	temp = NULL;
	cpy = 0;
	temp = stack->end;
	cpy = stack->end->value;
	while (temp->back)
	{
		temp->value = temp->back->value;
		temp = temp->back;
	}
	stack->start->value = cpy;
	return(0);
}

int		ft_rotate_stack(t_stack *stack)
{
	t_list	*temp;
	int		cpy;

	if (ft_stack_empty(stack))
		return (1);
	if (stack->start == stack->end)
		return (1);
	temp = NULL;
	cpy = 0;
	temp = stack->start;
	cpy = stack->start->value;
	while (temp->next)
	{
		temp->value = temp->next->value;
		temp = temp->next;
	}
	stack->end->value = cpy;
	return (0);
}

int	ft_swap_stack(t_stack *stack)
{
	t_list	*temp;
	int value;
	int first;
	int	second;

	if (ft_stack_empty(stack))
		return (1);
	if (stack->start == stack->end)
		return (1);
	temp = NULL;
	value = 0;
	first = stack->start->value;
	second = stack->start->next->value;
	stack = ft_stack_delfront(stack);
	stack = ft_stack_delfront(stack);
	stack = ft_stack_addfront(stack, first);
	stack = ft_stack_addfront(stack, second);
	return (0);
}

int		ft_push_stack(t_stack *dest, t_stack *src)
{
	if (ft_stack_empty(src))
		return (1);
	dest = ft_stack_addfront(dest, (src)->start->value);
	(dest)->start->value = (src)->start->value;
	src = ft_stack_delfront(src);
	return (0);
}

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_3(t_push *a)
{
	t_stack *stack;

	a->minus = stack->start->value;
	a->middle = stack->start->next->value;
	a->max = stack->end->value;
	if (a->minus == 3 && a->middle == 2 && a->max == 1)
	{
		ft_rra(a);
		printf("coucou\n");
	}	
	if (a->minus == 2 && a->middle == 3 && a->max == 1)
	{
		ft_sa(a);
		ft_rra(a);
	}
	if (a->minus == 1 && a->middle == 3 && a->max == 2)
	{
		ft_rra(a);
		ft_sa(a);
	}
	if (a->minus == 2 && a->middle == 1 && a->max == 3)
		ft_sa(a);
	if (a->minus == 3 && a->middle == 1 && a->max == 2)
	{
		ft_rra(a);
		ft_sa(a);
	}
	if (a->minus == 1 && a->middle == 2 && a->max == 3)
		return ;
}

int main()
{
	t_stack	*stack_a;
	//t_stack	*stack_b;

	 //stack_b = ft_new_stack(2);
	// stack_a = ft_stack_addfront(stack_a, 56);
	// stack_a = ft_stack_addfront(stack_a, 96);
	// stack_a = ft_stack_addfront(stack_a, 236);
	// print_list(stack_a);
	// print_list(stack_b);
	// printf("j'ai push ma stack a dans la b\n");
	// ft_push_stack(&stack_b, &stack_a);
	// ft_push_stack(&stack_b, &stack_a);
	// ft_push_stack(&stack_b, &stack_a);
	// ft_push_stack(&stack_b, &stack_a);
	// printf("stack_a\n");
	// print_list(stack_a);
	// printf("stack_b\n");
	// print_list(stack_b);
	stack_a = ft_new_stack(3);
	stack_a = ft_stack_addback(stack_a, 2);
	stack_a = ft_stack_addback(stack_a, 1);
	// stack_a = ft_stack_addback(stack_a, 4);
	// stack_a = ft_stack_addback(stack_a, 5);
	// stack_a = ft_stack_addback(stack_a, 6);
	// stack_a = ft_stack_addback(stack_a, 7);
	// stack_a = ft_stack_addback(stack_a, 8);
	// stack_a = ft_stack_addback(stack_a, 9);
	// stack_a = ft_stack_addback(stack_a, 10);
	// stack_a = ft_stack_addback(stack_a, 11);
	// stack_a = ft_stack_addback(stack_a, 12);
	// stack_a = ft_stack_addback(stack_a, 13);
	// print_list(stack_a);
	// printf("first print\n");
	// ft_swap_stack(stack_a);
	// print_list(stack_a);
	// printf("quatrieme print\n");
	// printf("J'ai effectué mon 1er move\n");
	// ft_sa(stack_a);
	// printf("J'ai effectué mon 2eme move\n");
	// ft_rra(stack_a);
	// ft_swap_stack(stack_a);
	// print_list(stack_a);
	ft_sort_3(stack_a);
	return 0;
}