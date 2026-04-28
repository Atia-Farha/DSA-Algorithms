#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertFirst(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertLast(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* currentNode = head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
}

void insertAt(int data, int position) {
    if (position == 0) {
        insertFirst(data);
        return;
    }

    struct Node* currentNode = head;

    for (int i = 0; currentNode != NULL && i < position - 1; i++) {
        currentNode = currentNode->next;
    }

    if (currentNode == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = currentNode->next;
    currentNode->next = newNode;
}

void deleteFirst() {
    if (head == NULL) return;

    struct Node* tempNode = head;
    head = head->next;
    free(tempNode);
}

void deleteLast() {
    if (head == NULL) return;

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* currentNode = head;

    while (currentNode->next->next != NULL) {
        currentNode = currentNode->next;
    }

    free(currentNode->next);
    currentNode->next = NULL;
}

void deleteItem(int item) {
    struct Node* currentNode = head;
    struct Node* previousNode = NULL;

    while (currentNode != NULL) {
        if (currentNode->data == item) {
            if (previousNode == NULL) {
                head = currentNode->next;
            }
            else {
                previousNode->next = currentNode->next;
            }

            free(currentNode);
            return;
        }

        previousNode = currentNode;
        currentNode = currentNode->next;
    }
}

void updateItem(int position, int newData) {
    struct Node* currentNode = head;

    for (int i = 0; currentNode != NULL && i < position; i++)
        currentNode = currentNode->next;

    if (currentNode == NULL) {
        printf("Invalid position\n");
        return;
    }

    currentNode->data = newData;
}

void reverseList() {
    struct Node* previousNode = NULL;
    struct Node* currentNode = head;
    struct Node* nextNode;

    while (currentNode != NULL) {
        nextNode = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
    }

    head = previousNode;
}

int searchItem(int item) {
    struct Node* currentNode = head;
    int position = 0;

    while (currentNode != NULL) {
        if (currentNode->data == item) {
            return position;
        }

        currentNode = currentNode->next;
        position++;
    }

    return -1;
}

int detectCycle() {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return 1;
        }
    }

    return 0;
}

struct Node* findMiddle() {
    if (head == NULL) {
        return NULL;
    }

    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void printList() {
    struct Node* currentNode = head;

    while (currentNode != NULL) {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->next;
    }

    printf("NULL\n");
}