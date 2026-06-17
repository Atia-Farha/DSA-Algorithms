#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

int isEmpty() {
    return top == -1;
}

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (isEmpty()) {
        return -1;
    }
    return stack[top--];
}

int graph[MAX][MAX];

void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void performDFS(int startNode, int vertices) {
    int visited[MAX] = {0};
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

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            graph[i][j] = 0;
        }
    }

    addEdge(10, 30);
    addEdge(10, 20);
    addEdge(20, 40);
    addEdge(20, 50);
    addEdge(30, 60);

    performDFS(10, MAX);

    return 0;
}