#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

int isEmpty() {
    return top == NULL;
}

void push(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = x;
    n->next = top;
    top = n;
}

int pop() {
    if (isEmpty()) return -1;
    struct Node *t = top;
    int x = t->data;
    top = top->next;
    free(t);
    return x;
}

int peek() {
    if (isEmpty()) return -1;
    return top->data;
}

void display() {
    struct Node *t = top;
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}