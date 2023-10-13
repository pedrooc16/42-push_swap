#include "./includes/push_swap.h"

void	ft_atol(const char *str, int * i)
{
	long	checker;
	int		flag;

	flag = 1;
	checker = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-') {
			flag = -1;
		}
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		checker *= 10;
		checker += (flag *(*str - 48));
		str++;
	}
	if (checker <= -2147483648 && checker >= 2147483647)
		*i = 0;
		else 
		*i = 1;
}

int		ft_strcmp(char *first, char *second)
{
 	while (*first && *second && *first == *second) 
	{
		first++;
		second++;
    }
    return (*first - *second);
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
