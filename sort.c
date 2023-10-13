#include "./includes/push_swap.h"
#include "./libft/libft.h"

//função para acharmos o maior numero de bits
int	get_max(node **stack)
{
	node	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->order;
	max_bits = 0;
	while (head)
	{
		if (head->order > max)
			max = head->order;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_radix(node **stack_a, node **stack_b)
{
	int		max;
	int		size;
	int		i;

	max = get_max(stack_a);
	size = get_size(stack_a);
	i = 0;
	while (i < max)
	{
		size = get_size(stack_a);
		while (size > 0)
		{
			if ((((*stack_a)->order >> i) & 1) != 1)
				pb(stack_a, stack_b);
			else	
				ra(stack_a);
			size--;
		}
		while (get_size(stack_b) > 0)
		{
			pa(stack_b, stack_a);
		}
		i++;
	}
}
