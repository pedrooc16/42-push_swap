#include    "./includes/push_swap.h"
#include "./libft/libft.h"

void ra(node **head)
{
    if (rotate(head))
    	write(1, "ra\n", 3);
    return;
}

void	rb(node **head)
{
	if (rotate(head))
		write(1, "rb\n", 3);
	return;
	
}

void   rr(node **stack_a, node **stack_b)
{
    if (rotate(stack_a) && rotate(stack_b))
        write(1, "rr\n", 3);
    return;
}

void	rra(node **head)
{
	if (reverse_rotate(head))
		write(1, "rra\n", 4);
	return;
}

void	rrb(node **head)
{
	if (reverse_rotate(head))
		write(1, "rrb\n", 4);
	return;
}

void	rrr(node **stack_a, node **stack_b)
{
	if (reverse_rotate(stack_a) && reverse_rotate(stack_b))
		write(1, "rrr\n", 4);
	return;
}

void    sa(node **stack_a)
{
    if (swap(stack_a))
        write(1, "sa\n", 3);
    return;
}

void  sb(node **stack_b)
{
    if (swap(stack_b))
        write(1, "sb\n", 3);
    return; 
}

void    ss(node **stack_a, node **stack_b)
{
    if (swap(stack_a) && swap(stack_b))
        write(1, "ss\n", 3);
    return;
}

void	pa(node **stack_a, node **stack_b)
{
	if (push(stack_a, stack_b))
		write(1, "pa\n", 3);
	return;
}

void	pb(node **stack_b, node **stack_a)
{
	if (push(stack_b, stack_a))
		write(1, "pa\n", 3);
	return;
}