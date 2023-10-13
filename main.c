#include "./includes/push_swap.h"

int main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (!(check_args(av, ac)))
	{
        ft_free_array(av, ac);
		write(1, "error\n", 6);
			return (0);
	}
	else {
		node	*stacks[2];
        count_args(av, stacks, ac);
        where2go(stacks, stacks + 1);
       // print_list(stacks);
	return (1);
	}
}