#include "./includes/push_swap.h"

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

void	sort4(node **stack_a, node **stack_b)
{
	int		min;
	node	*temp;
	int		i;

	i = 0;
	min = (*stack_a)->number;
	temp = *stack_a;
	while (temp != NULL)
	{
		if (temp->next && temp->next->number < min)
			min = temp->next->number;
		temp = temp->next;
	}
	while (*stack_a)
	{
		if ((*stack_a)->number == min)
			{
				i = pb(stack_a, stack_b);
				if (i == 1)
				{		
					sort3(stack_a);
					break;
				}
			}	
			ra(stack_a);
	}
	pa(stack_b, stack_a);
}

void sort5(node **stack_a, node **stack_b) 
{   
	int		min;
	int		max;
	int		i;

	find_min_and_max(stack_a, &min, &max);
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
}
