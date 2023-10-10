#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct node
{
    int element;
    int order;
    node    *next;
} node ;

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_atol(const char *str, int * i);
int    check_args(char **av, int ac);
int	check_args2(char *av);
int		ft_strcmp(char *first, char *second);
void	ft_atol(const char *str, int * i);

#endif