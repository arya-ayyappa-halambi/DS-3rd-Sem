#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int val) {
    if (isFull()) {
        printf("Queue Overflow! Cannot enqueue %d\n", val);
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = val;
    printf("%d enqueued.\n", val);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front]);
    front++;
    if (front > rear) { // Reset queue when empty
        front = -1;
        rear = -1;
    }
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Linear Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
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