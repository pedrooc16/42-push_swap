#include "./includes/push_swap.h"

void    where2go(node **stack_a, node **stack_b)
{
    if (isOrdered(stack_a))
        ft_free_and_exit(stack_a);
    else if (get_size(stack_a) == 2)
            sa(stack_a);
    else if (get_size(stack_a) == 3)
            sort3(stack_a);
	else if (get_size(stack_a) == 4)
			sort4(stack_a, stack_b);
    else if (get_size(stack_a) <= 5)
		sort5(stack_a, stack_b);
	else if (get_size(stack_a) <= 500)
		sort_radix(stack_a, stack_b);
}

void	count_args(char **av, node **stack_a, int ac)
{
	char	**args;
	int		i;

	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		i = 0;
	}
	else 
	{
		args = av;
		i = 1;
	}
	initializeList(stack_a, args + i);
	if (!i)
	{
		free(args);
	}
}

	
