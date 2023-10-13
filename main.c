#include "./includes/push_swap.h"

int main(int ac, char **av)
{
	if (ac < 2 || !check_args(av, ac))
	{
		write(1, "error\n", 6);
		return (1);
	}
	else {
		node	*stacks[2];
		stacks[1] = NULL;
        count_args(av, stacks, ac);
        where2go(stacks, stacks + 1);
		return (0);
	}
}