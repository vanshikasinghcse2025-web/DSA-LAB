#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

int searchNode(struct Node* head, int key) {
    struct Node* current = head;
    int position = 1;

   while (current != NULL) {
        if (current->data == key) {
            return position; 
        }
        current = current->next;
        position++;
    }
    
    return -1; 
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int key, result;

    push(&head, 14);
    push(&head, 21);
    push(&head, 11);
    push(&head, 30);
    push(&head, 10);

    printf("Linked List: ");
    printList(head);

    
    printf("Enter the element to search: ");
    scanf("%d", &key);

    result = searchNode(head, key);

    if (result != -1) {
        printf("Element %d found at node position %d.\n", key, result);
    } else {
        printf("Element %d is not present in the linked list.\n", key);
    }

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
