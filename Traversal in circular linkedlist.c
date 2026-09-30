#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void traverseList(struct Node* head) {
  
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* current = head;
    printf("Circular Linked List elements: ");
    
     do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);       
    
    printf("(Head)\n");
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {

    struct Node* head = NULL;
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    head->next->next->next->next = head;
    traverseList(head);
    struct Node* current = head;
    struct Node* nextNode;
    if (head != NULL) {
        do {
            nextNode = current->next;
            free(current);
            current = nextNode;
        } while (current != head);
    }

    return 0;
}

