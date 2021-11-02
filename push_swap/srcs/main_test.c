#include "../includes/push_swap.h"

int	ft_stack_empty(t_stack *stack)
{
	if (stack == NULL)
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
	t_push *push;

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
	stack->len++;
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
	stack->len++;
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

	if (ft_stack_empty(stack))
		return (1);
	if (stack->start == stack->end)
		return (1);
	temp = stack->end;
	stack->end = temp->back;
	stack->start->back = temp;
	temp->next = stack->start;
	stack->start = temp;
	stack->start->back = NULL;
	stack->end->next = NULL;
	return(0);
}

int		ft_rotate_stack(t_stack *stack)
{
	t_list	*temp;

	if (ft_stack_empty(stack))
		return (1);
	if (stack->start == stack->end)
		return (1);
	temp = stack->start;
	stack->start = temp->next;
	stack->end->next = temp;
	stack->end = temp;
	stack->start->back = NULL;
	stack->end->next = NULL;
	return (0);
}

int	ft_swap_stack(t_stack *stack)
{
	int first;
	int	second;

	if (ft_stack_empty(stack))
		return (1);
	if (stack->start == stack->end)
		return (1);
	first = stack->start->value;
	second = stack->start->next->value;
	stack = ft_stack_delfront(stack);
	stack = ft_stack_delfront(stack);
	stack = ft_stack_addfront(stack, first);
	stack = ft_stack_addfront(stack, second);
	return (0);
}

int		ft_push_stack(t_stack **dest, t_stack **src)
{
	if (ft_stack_empty(*src))
		return (1);
	*dest = ft_stack_addfront(*dest, (*src)->start->value);
	(*dest)->start->value = (*src)->start->value;
	*src = ft_stack_delfront(*src);
	return (0);
}

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		ft_size_stack(t_stack * stack)
{
	t_list *temp;
	size_t size;

	if (ft_stack_empty(stack))
		return (-1);
	temp = stack->start;
	size = 0;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	
	return (size);
}

int		ft_stack_is_sort(t_stack *stack)
{
	t_list	*temp;
	
	if (ft_stack_empty(stack))
		return (-1);
	temp = stack->start;
	while (temp != NULL && temp->next != NULL)
	{
		if (temp->next->value < temp->value)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	ft_sort_3(t_push *push)
{
	if (push->stack_a->start->value < push->stack_a->start->next->value &&\
		push->stack_a->start->value < push->stack_a->end->value)
		{
			ft_sa(push);
			ft_ra(push);
		}
	else if (push->stack_a->start->value > push->stack_a->start->next->value &&\
			push->stack_a->start->value < push->stack_a->end->value)
		ft_sa(push);
	else if (push->stack_a->start->value < push->stack_a->start->next->value &&\
			push->stack_a->start->next->value > push->stack_a->end->value)
		ft_rra(push);
	else if (push->stack_a->start->value > push->stack_a->start->next->value &&\
			push->stack_a->start->next->value < push->stack_a->end->value)
		ft_ra(push);
	else
	{
			ft_sa(push);
			ft_rra(push);
	}
	return (0);
}



int		ft_get_index_min(t_stack *stack)
{
	int index;
	int next_value;
	int value;
	int pos;
	t_list *tmp;

	index = 1;
	pos = 1;
	value = stack->start->value;
	tmp = stack->start;
	while (tmp)
	{
		if (tmp->next)
		{
			next_value = tmp->next->value;
			if (value > next_value)
			{
				value = next_value;
				index = pos + 1;
			}
		}
		tmp = tmp->next;
		pos++;
	}
	return (index);
}

void	ft_sort_5(t_push *push)
{
	ft_pb(push);
	ft_pb(push);
	ft_sort_3(push);
}

void	ft_sort(t_push *push)
{
	if (ft_stack_is_sort(push->stack_a) && ft_size_stack(push->stack_a) == 2)
	 	ft_sa(push);
	else if (ft_stack_is_sort(push->stack_a) && ft_size_stack(push->stack_a) == 3)
		ft_sort_3(push);
	else if (ft_stack_is_sort(push->stack_a) && ft_size_stack(push->stack_a) == 5)
		ft_sort_5(push);	
}

int main()
{
	t_push *push;
	//int error;
	push = malloc(sizeof(t_push) * 1);
	push->stack_a = malloc(sizeof(push->stack_a));
	push->stack_a = ft_new_stack(4);
	push->stack_a = ft_stack_addback(push->stack_a, 6);
	push->stack_a = ft_stack_addback(push->stack_a, 8);
	push->stack_a = ft_stack_addback(push->stack_a, 66);
	push->stack_a = ft_stack_addback(push->stack_a, 2);
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
	//stack_a = ft_new_stack(3);
	//stack_a = ft_stack_addback(stack_a, 2);
	//stack_a = ft_stack_addback(stack_a, 1);
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
	 //print_list(push->stack_a);
	//  printf("first print\n");
	printf("stack_a\n");
	print_list(push->stack_a);
	printf("mon index est la ====> [%d]\n", ft_get_index_min(push->stack_a));
	ft_sort(push);
	ft_size_stack(push->stack_a);
	printf("stack_a\n");
	print_list(push->stack_a);
	printf("stack_b\n");
	print_list(push->stack_b);
	// printf("mon start de b est ======> [%d]\n", push->stack_b->start->value);
	//ft_sort_5(push);
	//printf("stack_a\n");
	//print_list(push->stack_a);
	//printf("stack_b\n");
	//print_list(push->stack_b);
	//  print_list(push->stack_a);
	//  //printf("quatrieme print\n");
	//  printf("J'ai effectué mon 1er move\n");
	//  ft_sa(push);
	//  print_list(push->stack_a);
	//  printf("J'ai effectué mon 2eme move\n");
	//  ft_rra(push);
	// print_list(push->stack_a);
	 //ft_swap_stack(stack_a);
// 	error = ft_stack_is_sort(push->stack_a);
// 	if (error == 1)
// 	 	printf("la stack est pas trié\n");
// 	 else if (error == -1)
// 	 	printf("ma stack vaut NULL\n");
// 	 else
// 	 	printf("la stack est trié\n");
// 	ft_sort_3(push);
	return 0;
}