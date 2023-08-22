#include <stdio.h>

typedef struct Node {
  int data;
  struct Node *Next;
} Node;



void AddElement(Node **Head, int Data, int Index) {
    Node *Temp = malloc(sizeof(Node));
    Temp->data = Data;
    Temp->Next = NULL;

    if (Index == 1) {
        Temp->Next = *Head;
        *Head = Temp;
        return;
    }

    int i = 0;
    Node *Temp2 = *Head;
    while (i < Index - 2) {
        Temp2 = Temp2->Next;
        i++;
    }
    Temp->Next = Temp2->Next;
    Temp2->Next = Temp;
}
int main() {

  Node *Head = NULL;

 AddElement(&Head, 2, 1);
 AddElement(&Head, 4, 2);
 AddElement(&Head, 3, 3);
 AddElement(&Head, 5, 2);
 AddElement(&Head, 7, 1);
}