#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


void insertAtBeginning(struct Node** headRef, int newData) {
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = newData;


    newNode->next = *headRef;

    
    *headRef = newNode;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}


void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    
    struct Node* head = NULL;

    printf("Inserting elements at the beginning...\n");
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 40);

    
    printf("Linked List: ");
    printList(head);

    
    freeList(head);

    return 0;
}
