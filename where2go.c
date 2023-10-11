#include "./includes/push_swap.h"
#include "./libft/libft.h"

void    where2go(node **stack_a, node **stack_b)
{
    if (isOrdered(stack_a))
        ft_free(stack_a);
    else if (get_size(stack_a) == 2)
            sa(stack_a);
    else if(get_size(stack_a) == 3)
            sort3(stack_a);
        else
        *stack_b = NULL;
}


void    sort3(node **stack_a)
{
    node    *temp1;

    //temp = *stack_a;
	temp1 = get_last(stack_a);
	if ((*stack_a)->number > (*stack_a)->next->number)
        sa(stack_a);
	if (temp1->number < (*stack_a)->next->number || temp1->number < (*stack_a)->next->number)
        rra(stack_a);
	if ((*stack_a)->number > (*stack_a)->next->number)
        sa(stack_a);
}