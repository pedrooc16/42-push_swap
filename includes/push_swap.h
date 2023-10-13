#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct node
{
    int     number;
    int     order;
    struct node *next;    
} node ;

#include "../libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_atol(const char *str, int * i);
int    check_args(char **av, int ac);
int	check_digits(char *av);
int    is_valid(char **av, int i);
void	count_args(char **av, node **stack_a, int ac);
int		ft_strcmp(char *first, char *second);
void	ft_atol(const char *str, int * i);
void	ft_free_array(char **av, int ac);
void    ft_free(node **head);
void ra(node **head);
void	rb(node **head);
void   rr(node **stack_a, node **stack_b);
void	rra(node **head);
void	rrb(node **head);
void	rrr(node **stack_a, node **stack_b);
void    sa(node **stack_a);
void  sb(node **stack_b);
void    where2go(node **stack_a, node **stack_b);
void    sort3(node **stack_a);
void	sort5(node	**stack_a, node **stack_b);
void    ss(node **stack_a, node **stack_b);
void initializeList(node **head, char **argv);
node    *create_node(char *tmp);
int		get_size(node **head);
int		isOrdered(node **head);
node	*get_last(node **head);
void get_order(node **head);
int    swap(node **head);
int    rotate(node **head);
int    push(node **stack1, node **stack2);
int    reverse_rotate(node **head);
void	pa(node **stack_b, node **stack_a);
int		pb(node **stack_a, node **stack_b);
void     print_list(node **head);
void	sort_radix(node **stack_a, node **stack_b);
int		get_max(node **head);
void	find_min_and_max(node **stack_a, int *min, int *max);
void	merge(node **stack_a, node **stack_b);
void	sort4(node **stack_a, node **stack_b);
void    ft_free_and_exit(node **head);

#endif