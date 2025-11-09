#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
    int data; 
    struct Node* prev; 
    struct Node* next; 
}; 
struct Node* createNode(int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = data; 
    newNode->prev = NULL; 
    newNode->next = NULL; 
    return newNode; 
} 
void insertEnd(struct Node** head, int data) { 
    struct Node* newNode = createNode(data); 
    if (*head == NULL) { 
        *head = newNode; 
        return; 
    } 
    struct Node* temp = *head; 
  while (temp->next != NULL) { 
        temp = temp->next;
           } 
    temp->next = newNode; 
    newNode->prev = temp; 
} 
void display(struct Node* head) { 
    struct Node* temp = head; 
    printf("Doubly Linked List: "); 
    while (temp != NULL) { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    } 
    printf("\n"); 
} 
int main() { 
    struct Node* head = NULL; 
    insertEnd(&head, 10); 
    insertEnd(&head, 20); 
    insertEnd(&head, 30); 
    insertEnd(&head, 40); 
    display(head); 
    return 0; 
} 