#include <stdio.h> 
#define SIZE 10 
void insert(int hashTable[], int key) { 
    int index = key % SIZE; 
    int start = index; 
    while (hashTable[index] != -1) { 
        index = (index + 1) % SIZE; 
        if (index == start) { 
            printf("\nHash table is full. Cannot insert key %d\n", key); 
            return; 
        } 
    } 
    hashTable[index] = key; 
} 
void display(int hashTable[]) { 
    printf("\nHash Table:\n"); 
    for (int i = 0; i < SIZE; i++) { 
        printf("Index %d -> %d\n", i, hashTable[i]); 
    } 
} 
int main() { 
    int hashTable[SIZE]; 
    int n, key; 
    for (int i = 0; i < SIZE; i++) 
  hashTable[i] = -1; 
    printf("Enter number of keys to insert: "); 
    scanf("%d", &n); 
    for (int i = 0; i < n; i++) { 
        printf("Enter key %d: ", i + 1); 
        scanf("%d", &key); 
        insert(hashTable, key); 
    } 
    display(hashTable); 
    return 0; 
} 