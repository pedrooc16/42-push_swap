void initializeList(node **head, char **argv) {
    
    *head = NULL;
    node *tmp = *head; 
    int i = -1;
    
    while (argv[++i])
    {
    node *new_node = (node *)malloc(sizeof(node));
    //if (!new_node)
    // free_and_exit();
    new_node->element = atoi(argv[i]);
    
    if (*head == NULL)
    {
      *head = new_node;
    }
    else 
    {
      tmp = new_node->next;
      
    }
    }