#include <stdio.h>
#include <stdlib.h>

#define N 100

int stack[N];
int top = -1;

int isFull() {
    return top == N - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int x) {
    if (isFull()) {
        printf("Stack Overflow\n");
    }
    else {
        stack[++top] = x;
    }
}

int pop() {
    if (isEmpty()) {
        return -1;
    }
    return stack[top--];
}

int graph[N][N];

void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void DFS(int startNode, int vertices) {
    int visited[N] = {0};
    int currentNode, i;

    push(startNode);

    printf("DFS Traversal: ");

    while (!isEmpty()) {
        currentNode = pop();

        if (!visited[currentNode]) {
            visited[currentNode] = 1;
            printf("%d ", currentNode);

            for (i = vertices - 1; i >= 0; i--) {
                if (graph[currentNode][i] == 1 && !visited[i]) {
                    push(i);
                }
            }
        }
    }
    printf("\n");
}

int main() {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            graph[i][j] = 0;
        }
    }

    addEdge(10, 30);
    addEdge(10, 20);
    addEdge(20, 40);
    addEdge(20, 50);
    addEdge(30, 60);

    DFS(10, N);

    return 0;
}