#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};


void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    *head_ref = new_node;
}


void deleteNode(struct Node** head_ref, int position) {
    
    if (*head_ref == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }

    struct Node* temp = *head_ref;

    
    if (position == 1) {
        *head_ref = temp->next;
        free(temp);            
        printf("Node at position 1 deleted successfully.\n");
        return;
    }

    
    struct Node* prev = NULL;
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    
    if (temp == NULL) {
        printf("Position %d is out of bounds.\n", position);
        return;
    }
    prev->next = temp->next;

    
    free(temp);
    printf("Node at position %d deleted successfully.\n", position);
}


int main() {
    struct Node* head = NULL;


    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 40);
    insertAtBeginning(&head, 50);

    printf("Original Linked List:\n");
    printList(head);

    deleteNode(&head, 3);
    printf("List after deleting node at position 3:\n");
    printList(head);

    
    deleteNode(&head, 1);
    printf("List after deleting node at position 1:\n");
    printList(head);
    

    while (head != NULL) {
        deleteNode(&head, 1);
    }

    return 0;
}
