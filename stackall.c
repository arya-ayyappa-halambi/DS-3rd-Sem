#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int val) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", val);
        return;
    }
    top++;
    stack[top] = val;
    printf("%d pushed onto stack.\n", val);
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }
    printf("Popped element: %d\n", stack[top]);
    top--;
}

void peek() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element: %d\n", stack[top]);
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}