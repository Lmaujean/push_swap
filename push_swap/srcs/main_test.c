#include "../includes/push_swap.h"

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

    if (!stack)
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

	if (!stack)
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

	if (!stack)
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

	if (!stack)
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
	t_list *tmp;\

	if (!stack)
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

	if (!stack)
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

	if (!stack)
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

	if (!stack)
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

int main()
{
    t_stack *stack;

	stack = ft_new_stack(96561);
	stack = ft_stack_addback(stack, 2565);
	stack = ft_stack_addback(stack, 3);
	stack = ft_stack_addback(stack, 4);
	stack = ft_stack_addback(stack, 5);
	stack = ft_stack_addback(stack, 6);
	stack = ft_stack_addback(stack, 7);
	stack = ft_stack_addback(stack, 8);
	stack = ft_stack_addback(stack, 9);
	stack = ft_stack_addback(stack, 10);
	stack = ft_stack_addback(stack, 11);
	stack = ft_stack_addback(stack, 12);
	stack = ft_stack_addback(stack, 13);
	print_list(stack);
	printf("first print\n");
	ft_swap_stack(stack);
	print_list(stack);
	printf("quatrieme print\n");
	ft_swap_stack(stack);
	print_list(stack);
	return 0;
}