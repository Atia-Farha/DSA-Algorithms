#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

bool isEmpty() {
    return front == NULL;
}

void enqueue(int x) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (isEmpty()) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return;
    }

    struct Node* temp = front;
    printf("Dequeued: %d\n", front->data);

    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue elements: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void printFrontAndRear() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Front element: %d\n", front->data);
    printf("Rear element: %d\n", rear->data);
}