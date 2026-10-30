#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *link;
} Node;

Node* create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->data = data;
    new_node->link = NULL;
    return new_node;
}

Node* insert_beginning(Node *start, int val) {
    Node *new_node = create_node(val);
    if (new_node == NULL) {
        return start;
    }
    new_node->link = start;
    return new_node;
}

Node* insert_end(Node *start, int val) {
    Node *new_node = create_node(val);
    if (new_node == NULL) {
        return start;
    }
    if (start == NULL) {
        return new_node;
    }
    Node *curr = start;
    while (curr->link != NULL) {
        curr = curr->link;
    }
    curr->link = new_node;
    return start;
}

Node* insert_position(Node *start, int val, int pos) {
    if (pos < 1) {
        return start;
    }
    if (pos == 1) {
        return insert_beginning(start, val);
    }
    Node *curr = start;
    for (int i = 1; curr != NULL && i < pos - 1; i++) {
        curr = curr->link;
    }
    if (curr == NULL) {
        return start;
    }
    Node *new_node = create_node(val);
    if (new_node == NULL) {
        return start;
    }
    new_node->link = curr->link;
    curr->link = new_node;
    return start;
}

Node* search_node(Node *start, int target) {
    Node *curr = start;
    while (curr != NULL) {
        if (curr->data == target) {
            return curr;
        }
        curr = curr->link;
    }
    return NULL;
}

Node* delete_beginning(Node *start) {
    if (start == NULL) {
        return NULL;
    }
    Node *temp = start;
    start = start->link;
    free(temp);
    return start;
}

Node* delete_end(Node *start) {
    if (start == NULL) {
        return NULL;
    }
    if (start->link == NULL) {
        free(start);
        return NULL;
    }
    Node *curr = start;
    while (curr->link->link != NULL) {
        curr = curr->link;
    }
    free(curr->link);
    curr->link = NULL;
    return start;
}

Node* delete_position(Node *start, int pos) {
    if (start == NULL || pos < 1) {
        return start;
    }
    if (pos == 1) {
        return delete_beginning(start);
    }
    Node *curr = start;
    for (int i = 1; curr != NULL && i < pos - 1; i++) {
        curr = curr->link;
    }
    if (curr == NULL || curr->link == NULL) {
        return start;
    }
    Node *temp = curr->link;
    curr->link = temp->link;
    free(temp);
    return start;
}

Node* delete_node_without_head(Node *node_to_delete) {
    if (node_to_delete == NULL || node_to_delete->link == NULL) {
        return NULL;
    }
    Node *temp = node_to_delete->link;
    node_to_delete->data = temp->data;
    node_to_delete->link = temp->link;
    free(temp);
    return node_to_delete;
}

Node* count_nodes(Node *start, int *count) {
    *count = 0;
    Node *curr = start;
    while (curr != NULL) {
        (*count)++;
        curr = curr->link;
    }
    return start;
}

Node* display_list(Node *start) {
    if (start == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    Node *curr = start;
    printf("List: ");
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->link;
    }
    printf("NULL\n");
    return start;
}

Node* free_list(Node *start) {
    Node *curr = start;
    while (curr != NULL) {
        Node *temp = curr->link;
        free(curr);
        curr = temp;
    }
    return NULL;
}

int main(void) {
    Node *start = NULL;
    int choice, val, pos, total;

    while (1) {
        printf("\n--- Singly Linked List Operations ---\n");
        printf("1. Insert Beginning\n");
        printf("2. Insert End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete Beginning\n");
        printf("5. Delete End\n");
        printf("6. Delete at Position\n");
        printf("7. Delete Node without Head (by target value)\n");
        printf("8. Search Node\n");
        printf("9. Count Nodes\n");
        printf("10. Display List\n");
        printf("0. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            break;
        }

        if (choice == 0) {
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                start = insert_beginning(start, val);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                start = insert_end(start, val);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &val);
                printf("Enter 1-based position: ");
                scanf("%d", &pos);
                start = insert_position(start, val, pos);
                break;

            case 4:
                start = delete_beginning(start);
                break;

            case 5:
                start = delete_end(start);
                break;

            case 6:
                printf("Enter 1-based position: ");
                scanf("%d", &pos);
                start = delete_position(start, pos);
                break;

            case 7:
                printf("Enter target value: ");
                scanf("%d", &val);
                {
                    Node *target = search_node(start, val);
                    if (target != NULL) {
                        delete_node_without_head(target);
                    }
                }
                break;

            case 8:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if (search_node(start, val) != NULL) {
                    printf("Value found.\n");
                } else {
                    printf("Value not found.\n");
                }
                break;

            case 9:
                count_nodes(start, &total);
                printf("Total nodes: %d\n", total);
                break;

            case 10:
                display_list(start);
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    start = free_list(start);
    return 0;
}