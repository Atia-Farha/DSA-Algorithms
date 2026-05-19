#include <stdio.h>
#include <stdbool.h>

#define N 100

int q[N], front = -1, rear = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return rear == N - 1;
}

void enqueue(int x) {
    if (isFull()) return;

    if (isEmpty()) {
        front = rear = 0;
    }
    else {
        rear++;
    }

    q[rear] = x;
}

int dequeue() {
    if (isEmpty()) return -1;

    int x = q[front];

    if (front == rear) {
        front = rear = -1;
    }
    else {
        front++;
    }

    return x;
}

int frontElement() {
    if (isEmpty()) return -1;
    return q[front];
}

int rearElement() {
    if (isEmpty()) return -1;
    return q[rear];
}

void display() {
    for (int i = front; i <= rear; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}