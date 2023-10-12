#include "./includes/push_swap.h"
#include "./libft/libft.h"

void    where2go(node **stack_a, node **stack_b)
{
    if (isOrdered(stack_a))
        ft_free(stack_a);
    else if (get_size(stack_a) == 2)
            sa(stack_a);
    else if (get_size(stack_a) == 3)
            sort3(stack_a);
    else if (get_size(stack_a) <= 5)
		sort5(stack_a, stack_b);
	else if (get_size(stack_a) <= 100)
	{
		node	*temp;
		get_order(stack_a);
		temp = *stack_a;
		while (temp != NULL)
		{
			printf("%d is and order is %d\n", temp->number, temp->order);
			temp = temp->next;
		}
		sort_radix(stack_a, stack_b);
	}
}


void    sort3(node **stack_a)
{
    node    *temp1;

	temp1 = get_last(stack_a);
	//primeiro, verificar se o primeiro é maior que o segundo, se sim trocar. condição especifica para 3 1 2 
	if ((*stack_a)->number > (*stack_a)->next->number)
	{
		if ((*stack_a)->next->number < temp1->number && temp1->number < (*stack_a)->number)
			ra(stack_a);
	}
	if ((*stack_a)->number > (*stack_a)->next->number)
    {
        sa(stack_a);
    }

	if ((*stack_a)->next->number > temp1->number) // 2 1 3
	{
			rra(stack_a);
			temp1 = get_last(stack_a);
			if ((*stack_a)->number > (*stack_a)->next->number)
        		sa(stack_a);
	}
}

void	find_min_and_max(node **stack_a, int *min, int *max)
{
	node	*temp;
	*min =	(*stack_a)->number;
	*max = (*stack_a)->number;

	temp = *stack_a;
	while (temp != NULL)
	{
		if (temp->number < *min)
			*min = temp->number;
		if (temp->number > *max)
		*max = temp->number;
	temp = temp->next;
	}
}

void sort5(node **stack_a, node **stack_b) 
{   
	int		min;
	int		max;
	find_min_and_max(stack_a, &min, &max);
	int		i;

	i = 0;
	while ((*stack_a))
	{
		if ((*stack_a)->number == min || (*stack_a)->number == max)
		{
			pb(stack_a, stack_b);
			i++;
				if (i == 2)
			break;
		}	
		else 
			ra(stack_a);
	}
	sort3(stack_a);
	merge(stack_a, stack_b);
	
}

void	merge(node **stack_a, node **stack_b)
{
	int		i;

	i = 0;
	if ((*stack_b)->number > (*stack_a)->number)
	{
		pa(stack_b, stack_a);
		ra(stack_a);
		i = 1;
	} 
	else if ((*stack_b)->number < (*stack_a)->number)
		pa(stack_b, stack_a);
	pa(stack_b, stack_a);
	if (!i)
		ra(stack_a);
	node *temp = *stack_a;
	while (temp != NULL)
	{
		printf("%d\n", temp->number);
		temp = temp->next;
	}
}
	
