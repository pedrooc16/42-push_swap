void initializeList(node **head, char **argv) 
{    
	node *tmp;
	node	*new_node; 
	int i;
    
	i = -1;
    while (argv[++i])
    {
      if (!(new_node = (node *)malloc(sizeof(node))))
        free(new_node);
      new_node->element = atoi(argv[i]);
      new_node->next = NULL;
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
	while (temp->next != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int		isOrdered(node **head)
{
	 if (*head == NULL || (*head)->next == NULL) 
        // Lista vazia ou com apenas um elemento, considerada ordenada
        return 1;
	node	*temp;
	int		isOrdered;

	isOrdered = 1;
	temp = *head;
	while (temp->next != NULL)
	{
		if (temp->element > temp->next->element)
		{
		isOrdered = 0;
		return (isOrdered);
		}
		temp = temp->next;
	}
	return (isOrdered);
}

void get_order(node **head, int argc) {
   
    node *current = *head;
	node	*min_node;
    int order = 1;

    while (order <= argc) 
	{
        // Inicializa o valor mínimo e o nó correspondente
        int min_number = 24888743; // Use INT_MAX como um valor inicial máximo.
        *min_node = NULL;

        // Percorre a lista para encontrar o valor mínimo entre os nós não marcados
        while (current != NULL) {
            if (current->order == 0 && current->number < min_number) {
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
