//função para acharmos o maior numero de bits
int  get_max(node **head)
{
 node *temp = *head;
  int max;
  int bits;
  
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