#include "./includes/push_swap.h"
#include "./libft/libft.h"

//esta função libera a memoria alocada pela função split
void	ft_free_array(char **av, int ac)
{
	int i;

	i = 0;
	if (ac != 2)
		return;

	while (av[i])
	{
		free(av[i]);
		i++;
	}
}

// esta função faz free da memoria caso haja algum problema
// com a alocaçao de memoria da linked list
void    ft_free(node **head)
{
    node    *temp;
    node    *current;

    temp = *head;
	current = NULL;
	if (*head)
	{
    	while (temp != NULL)
    	{
        current = temp->next;
		free(temp);
		temp = current;
    	}
	}	
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}