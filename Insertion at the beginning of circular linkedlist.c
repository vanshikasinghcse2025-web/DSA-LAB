#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtBeginning(struct Node* tail, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("\n[Error] Memory allocation failed!\n");
        return tail;
    }
    newNode->data = value;

    if (tail == NULL) {
        tail = newNode;
        newNode->next = tail; 
    } else {
        newNode->next = tail->next; 
        tail->next = newNode;       
    }
    printf("\nNode with value %d successfully inserted at the beginning.\n", value);
    return tail;
}


void displayList(struct Node* tail) {
    if (tail == NULL) {
        printf("\nThe list is currently empty.\n");
        return;
    }

    struct Node* temp = tail->next; 
    printf("\nCurrent Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != tail->next); 
    printf("(head)\n");
}

int main() {
    struct Node* tail = NULL; 
    int choice, value;

    while (1) {
       
        printf("\n=== Circular Linked List Menu ===");
        printf("\n1. Insert at the beginning");
        printf("\n2. Display the list");
        printf("\n3. Exit");
        printf("\nEnter your choice (1-3): ");
        
       
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the integer value to insert: ");
                scanf("%d", &value);
                tail = insertAtBeginning(tail, value);
                break;

            case 2:
                displayList(tail);
                break;

            case 3:
                printf("\nExiting program and clearing memory...\n");
              
                if (tail != NULL) {
                    struct Node* head = tail->next;
                    struct Node* temp;
                    tail->next = NULL;
                    while (head != NULL) {
                        temp = head;
                        head = head->next;
                        free(temp);
                    }
                }
                return 0;

            default:
                printf("\nInvalid choice! Please select an option between 1 and 3.\n");
        }
    }
    return 0;
}
