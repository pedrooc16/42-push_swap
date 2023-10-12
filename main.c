#include "./includes/push_swap.h"
#include "./libft/libft.h"

int main(int ac, char **av)
{
	node	*stacks[2];
        stacks[1] = NULL;
	if (!(count_args(av, ac))){
        ft_free_array(av, ac);
		write(1, "error\n", 6);
			return (0);
		}
        initializeList(stacks, av + 1);
        where2go(stacks, stacks + 1);
       // print_list(stacks);
	return 1;
}