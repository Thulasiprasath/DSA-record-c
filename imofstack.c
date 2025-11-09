#include <stdio.h> 
#define MAXSIZE 8 
int stack[MAXSIZE]; 
int top = -1; 
int isempty()  
{ 
    return top == -1; 
} 
int isfull() { 
    return top == MAXSIZE - 1;
    } 
int peek() { 
    if (!isempty()) 
        return stack[top]; 
    else 
        printf("Stack is empty\n"); 
    return -1; 
} 
int pop() { 
    if (!isempty()) 
        return stack[top--]; 
    else { 
        printf("Could not retrieve data, Stack is empty.\n"); 
        return -1; 
    } 
} 
void push(int data) { 
    if (!isfull()) 
        stack[++top] = data; 
    else 
        printf("Could not insert data, Stack is full.\n");
        } 
int main() { 
    push(44); 
    push(10); 
    push(62);
      push(123); 
    push(15); 
printf("Element at top of the stack: %d\n", peek()); 
  printf("Elements: \n"); 
    while (!isempty()) { 
        printf("%d\n", pop()); 
    } 
 printf("Stack full: %s\n", isfull() ? "true" : "false"); 
  printf("Stack empty: %s\n", isempty() ? "true" : "false"); 
 return 0; 
} 
