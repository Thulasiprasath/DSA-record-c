#include <stdio.h> 
#include <stdlib.h> 
#define MAX 5 
typedef struct { 
    int items[MAX]; 
    int front; 
    int rear; 
} Queue; 
void initializeQueue(Queue *q) { 
    q->front = -1; 
    q->rear = -1; 
} 
int isEmpty(Queue *q) { 
    return (q->front == -1); 
} 
int isFull(Queue *q) { 
    return (q->rear == MAX - 1);
}
void enqueue(Queue *q, int element) { 
    if (isFull(q)) { 
        printf("Queue Overflow! Cannot insert %d\n", element); 
    } else { 
        if (q->front == -1) q->front = 0; // First element 
        q->rear++; 
        q->items[q->rear] = element; 
        printf("%d enqueued to queue\n", element); 
    } 
} 
int dequeue(Queue *q) { 
    if (isEmpty(q)) { 
        printf("Queue Underflow! Cannot dequeue\n"); 
        return -1; 
    } else { 
        int element = q->items[q->front]; 
        if (q->front == q->rear) { 
            // Queue becomes empty 
            q->front = -1; 
            q->rear = -1; 
        } else { 
            q->front++; 
        } 
        return element;
    }
}
void displayQueue(Queue *q) { 
    if (isEmpty(q)) { 
        printf("Queue is empty\n"); 
    } else { 
        printf("Queue elements: "); 
        for (int i = q->front; i <= q->rear; i++) { 
            printf("%d ", q->items[i]); 
        } 
        printf("\n"); 
    } 
} 
int main() { 
    Queue q; 
    initializeQueue(&q); 
    enqueue(&q, 10); 
    enqueue(&q, 20); 
    enqueue(&q, 30); 
    displayQueue(&q);  printf("Dequeued: %d\n", dequeue(&q)); 
    displayQueue(&q); 
    enqueue(&q, 40); 
    enqueue(&q, 50); 
    enqueue(&q, 60); // Should show overflow 
    displayQueue(&q); 
printf("Dequeued: %d\n", dequeue(&q)); 
    displayQueue(&q); 
  return 0;
}