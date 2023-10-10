/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecosta- <pecosta-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:02:38 by pecosta-          #+#    #+#             */
/*   Updated: 2023/10/09 19:29:11 by pecosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int    swap(node **head) //sa and sb
{
    if (*head == NULL || (*head)->next == NULL) 
    {
        return (0);
    } 
    node    *first;
    node    *second;

    first = *head;
    second = (*head)->next;
    first->next = second->next;
    second->next = first;
    *head = second; 
	return (1);
}

int    rotate(node **head) // ra and rb 
{
    if (*head == NULL || (*head)->next == NULL)
        return (0);
    node   *first;
    node    *tmp;

    tmp = *head; 
    first = get_last(head);
    *head = *(head)->next;
    first->next = tmp;
    tmp->next = NULL;
	return (1);
}

int    push(node **stack1, node **stack2) //pa and pb 
{
    if (*stack1 == NULL)
        return (0);
    
    node    *temp_stack1;
    node    *temp_stack2;
     //aponta para o segundo da lista
    if (*stack2 == NULL) //caso a lista esteja vazia
    {
        *stack2 = *stack1;
        *stack1 = (*stack1)->next;
        (*stack2)->next = NULL;
    }
    else {
        temp_stack1 = *stack1;
        temp_stack2 = *stack2;
        *stack1 = temp_stack1->next; //atualizo a lista para apontar para o 2 elemento
        *stack2 = temp_stack1; // b agora aponta para o primeiro elemento da lista de a 
        (*stack2)->next = temp_stack2;    
    }
    return (1);
}

int    reverse_rotate(node **head) //rra and rrb
{
    if (*head == NULL || (*head)->next == NULL)
        return (0);
        
    node    *temp;
    node    *temp1;
    node    *last;
    
    temp = *head;
    temp1 = *head;
    last = get_last(head);
    while (temp1->next) 
    {
        if (temp1->next->next == NULL)
            break;
        temp1 = temp1->next;
    }
    *head = last;
    temp1->next = NULL;
    last->next = temp;
    return (1);
}
