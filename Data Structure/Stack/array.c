#include <stdio.h>

#define N 100
int stack[N], top = -1;

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

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
    }
    else {
        printf("Popped: %d\n", stack[top--]);
    }
}

void peek() {
    if (isEmpty()) {
        printf("Stack is Empty\n");
    }
    else {
        printf("Top Element: %d\n", stack[top]);
    }
}

void display() {
    if (isEmpty()) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack Elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}