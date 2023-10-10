#include "./includes/push_swap.h"

//função para acharmos o maior numero de bits
int		get_max(node **head)
{
 node *temp;
  int max;
  int bits;
  
  temp = *head;
  max = (*head)->order;
  bits = 0;
  while (temp != NULL)
 { 
   if (temp->order > max)
   {
    max = temp->order; 
   }
   temp = temp->next;
 }
  while (1)
 {
  max >>= bits;
  bits++; 
  if (max == 0)
    break;
 }
 return (bits);
}

void	sort_radix(node **stack_a, node **stack_b)
{
	int		max;
	int		size;

	max = get_max(stack_a);
	size = 0;
	i = 0;
	while (i < max)
	{
		size = get_size(stack_a);
		while (size != 0)
		{
			if (((*stack_a)->order >> i && 1) != 0)
				ra(stack_a);
			pa(stack_a, stack_b);
			size--;
		}
		while (get_size(stack_b) > 0)
		{
			pb(stack_b, stack_a);
		}
		i++;
	}
}
