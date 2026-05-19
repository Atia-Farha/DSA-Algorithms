#include <stdio.h>
#include <string.h>

#define N 100
char stack[N];
int top = -1;

int isEmpty() {
    return top == -1;
}

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

void reverseString(char* str) {
    int len = strlen(str);
    
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }
    
    for (int i = 0; i < len; i++) {
        str[i] = pop();
    }
}

void reverseWords(char* str) {
    char result[N];
    int k = 0;

    for (int i = 0; ; i++) {

        if (str[i] != ' ' && str[i] != '\0') {
            push(str[i]);
        }
        else {
            while (!isEmpty()) {
                result[k++] = pop();
            }

            if (str[i] == ' ') {
                result[k++] = ' ';
            }
            else {
                break;
            }
        }
    }

    result[k] = '\0';
    strcpy(str, result);
}

int main() {
    char str[N];

    printf("Enter string: ");
    fgets(str, N, stdin);
    str[strcspn(str, "\n")] = '\0';

    reverseWords(str);

    printf("Reversed words: %s\n", str);

    return 0;
}