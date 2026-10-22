#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

int isEmpty() {
    return front == -1;
}

void insertFront(int val) {
    if (isFull()) {
        printf("Deque Overflow! Cannot insert %d at front.\n", val);
        return;
    }

    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = MAX - 1; // Wrap around to end
    } else {
        front--;
    }

    deque[front] = val;
    printf("%d inserted at front.\n", val);
}

void insertRear(int val) {
    if (isFull()) {
        printf("Deque Overflow! Cannot insert %d at rear.\n", val);
        return;
    }

    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0; // Wrap around to beginning
    } else {
        rear++;
    }

    deque[rear] = val;
    printf("%d inserted at rear.\n", val);
}

void deleteFront() {
    if (isEmpty()) {
        printf("Deque Underflow! Deque is empty.\n");
        return;
    }

    printf("Deleted from front: %d\n", deque[front]);

    if (front == rear) { // Only one element was present
        front = -1;
        rear = -1;
    } else if (front == MAX - 1) {
        front = 0; // Wrap around
    } else {
        front++;
    }
}

void deleteRear() {
    if (isEmpty()) {
        printf("Deque Underflow! Deque is empty.\n");
        return;
    }

    printf("Deleted from rear: %d\n", deque[rear]);

    if (front == rear) { // Only one element was present
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1; // Wrap around
    } else {
        rear--;
    }
}

void getFront() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Front element: %d\n", deque[front]);
}

void getRear() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Rear element: %d\n", deque[rear]);
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n--- Double-Ended Queue (Deque) Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Get Front\n");
        printf("6. Get Rear\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &val);
                insertFront(val);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &val);
                insertRear(val);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                getFront();
                break;
            case 6:
                getRear();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}