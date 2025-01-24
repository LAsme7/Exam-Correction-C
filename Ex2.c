#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "list.c"
Node* head;
void Reverse_DLL(Node** head){
 Node* temp = NULL;
 Node* current = *head;
 while (current!= NULL){
   temp = getPrev(current);
   setPrev(current,getNext(current));
   setNext(current,temp);
   current = getPrev(current);
 }
 if (temp != NULL){
    *head = getPrev(temp);
 }
}

int main()
{
    head = NULL;
    Node* node1 = createNode(10);
    Node* node2 = createNode(20);
    Node* node3 = createNode(30);
    setNext(node1, node2);
    setPrev(node2, node1);

    setNext(node2, node3);
    setPrev(node3, node2);
    head = node1;
     printf("List contents (forward):\n");
    Node* current = head;
    while (current != NULL) {
        printf("%d ", getValue(current));
        current = getNext(current);
    }
    printf("\n");
    Reverse_DLL(&head);
    printf("Reversed list :\n");
        current = head;

    while (current != NULL) {
        printf("%d ", getValue(current));
        current = getNext(current);
    }
    printf("\n");
    return 0;
}
