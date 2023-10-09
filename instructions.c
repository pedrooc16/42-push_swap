#include    "./includes/push_swap.h"

void ra(node **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return;
        rotate(head);
        write(1, "ra\n", 3);
}

void	rb(node **head)
{
	if (*head == NULL || (*head)->next == NULL)
        return;
		if (rotate(head))
			write(1, "rb\n", 3);
		return;
	
}

void   rr(node **stack_a, node **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    write(1, "rr\n", 3);
}

void	rra(node **head)
{
	if (reverse_rotate(head))
		write(1, "rra\n", 4);
	return;
}

void	rra(node **head)
{
	if (reverse_rotate(head))
		write(1, "rrb\n", 4);
	return;
}

void	rrb(node **head)
{
	if (reverse_rotate(head))
		write(1, "rrb\n", 4);
	return;
}

void	rrb(node **stack_a, node **stack_b)
{
	if (reverse_rotate(stack_a) && reverse_rotate(stack_b))
		write(1, "rrb\n", 4);
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