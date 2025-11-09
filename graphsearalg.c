#include <stdio.h> 
#define MAX 10 
int adj[MAX][MAX];   
int visited[MAX]; 
int queue[MAX]; 
int front = -1, rear = -1; 
void bfs(int start, int n); 
void dfs(int start, int n); 
int main() { 
    int n, i, j, start; 
    printf("Enter number of vertices: "); 
    scanf("%d", &n); 
    printf("Enter the adjacency matrix:\n"); 
    for (i = 0; i < n; i++) { 
        for (j = 0; j < n; j++) { 
            scanf("%d", &adj[i][j]); 
        } 
    } 
    printf("Enter starting vertex (0 to %d): ", n - 1); 
    scanf("%d", &start); 
    for (i = 0; i < n; i++) 
        visited[i] = 0; 
    printf("\nBFS Traversal: "); 
    bfs(start, n); 
    for (i = 0; i < n; i++)
       visited[i] = 0; 
    printf("\nDFS Traversal: "); 
    dfs(start, n); 
    printf("\n"); 
    return 0; 
} 
void bfs(int start, int n) { 
    int i, v; 
    front = rear = -1; 
    queue[++rear] = start; 
    visited[start] = 1; 
    while (front != rear) { 
        v = queue[++front]; 
        printf("%d ", v); 
for (i = 0; i < n; i++) { 
            if (adj[v][i] == 1 && visited[i] == 0) { 
                queue[++rear] = i; 
                visited[i] = 1; 
            } 
        } 
    } 
} 
void dfs(int start, int n) { 
    int i; 
    printf("%d ", start); 
    visited[start] = 1;
        for (i = 0; i < n; i++) { 
        if (adj[start][i] == 1 && visited[i] == 0) 
            dfs(i, n); 
    } 
} 
