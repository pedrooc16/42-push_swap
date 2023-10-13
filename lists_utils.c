#include "./includes/push_swap.h"
#include "./libft/libft.h"

void initializeList(node **head, char **argv) 
{    
	node *tmp;
	node	*new_node; 
	int i;
    
	i = -1;
    new_node = NULL;
    while (argv[++i])
    {
       new_node = create_node(argv[i]);
       if (new_node == NULL)
        {
            ft_free(head);
        }
      if (*head == NULL)
      {
      *head = new_node;
      tmp = *head;
      }
      else 
      {
      tmp->next = new_node;
      tmp = new_node;
      } 
    }
}

void     print_list(node **head)
{
    node    *temp;

    temp = *head;

    while (temp != NULL)
    {
        printf("%d\n", temp->number);
        temp = temp->next;
    }
}

node    *create_node(char *tmp)
{
    node    *new_node;

    new_node = NULL;
     if (!(new_node = (node *)malloc(sizeof(node))))
            return (new_node);
        new_node->number = atoi(tmp);
        new_node->order = -1;
        new_node->next = NULL;
    return (new_node);
}

int		get_size(node **head)
{
	 if (*head == NULL) 
	{
        return 0; // Retorna 0 se a lista está vazia
    }
	int		i;
	node	*temp;

	temp = *head;
	i = 0;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int		isOrdered(node **head)
{
	 if (*head == NULL || (*head)->next == NULL) 
        return (1);
	node	*temp;
	int		isOrdered;

	isOrdered = 1;
	temp = *head;
	while (temp->next != NULL)
	{
		if (temp->number > temp->next->number)
		{
		isOrdered = 0;
		return (isOrdered);
		}
		temp = temp->next;
	}
	return (isOrdered);
}

node	*get_last(node **head)
{	
	node	*tmp;

	tmp = *head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void get_order(node **head)
{   
    node *current = *head;
	node	*min_node;
    int order;

    order = 0;
    while (1) 
	{
        // Inicializa o valor mínimo e o nó correspondente
        int min_number = 24888743; // Use INT_MAX como um valor inicial máximo.
        min_node = NULL;
        // Percorre a lista para encontrar o valor mínimo entre os nós não marcados
        while (current != NULL) {
            if (current->order == -1 && current->number < min_number) {
                min_number = current->number;
                min_node = current;
            }
            current = current->next;
        }
        // Se encontramos um valor mínimo, atribuímos a ordem e incrementamos
        if (min_node != NULL) {
            min_node->order = order;
            order++;
        } else {
            // Não encontramos um valor mínimo, terminamos a iteração
            break;
        }
        // Reinicializamos para a próxima iteração
        current = *head;
    }
}
