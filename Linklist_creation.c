#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    char choice;

    do {
        // 1. Allocate memory for a new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter data for the node: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode; 
            temp = newNode;
        } else {
            temp->next = newNode; 
            temp = newNode;       
        }

        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &choice); 

    } while (choice == 'y' || choice == 'Y');


    printf("\n--- Created Linked List ---\n");
    temp = head;
    while (temp != NULL) {
        printf("[%d] -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    temp = head;
    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}
