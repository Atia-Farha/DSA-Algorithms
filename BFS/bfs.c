#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100

int Queue[N], front = -1, rear = -1;

bool isFull() {
    return rear == N - 1;
}

bool isEmpty() {
    return front == -1 && rear == -1;
}

void enqueue(int x) {
    if (isFull()) {
        printf("Queue overflow\N");
    }
    else if (isEmpty()) {
        front = rear = 0;
        Queue[rear] = x;
    }
    else {
        Queue[++rear] = x;
    }
}

int dequeue() {
    if (isEmpty()) return -1;

    int x = Queue[front];

    if (front == rear) {
        front = rear = -1;
    }
    else {
        front++;
    }

    return x;
}

int graph[N][N];
int visited[N];
int vertices;

void BFS(int start) {
    int i, current;

    for (i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (!isEmpty()) {
        current = dequeue();
        printf("%d ", current);

        for (i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int i, j, edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\N");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        // graph[v][u] = 1; // uncomment for undirected
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    BFS(start);

    return 0;
}