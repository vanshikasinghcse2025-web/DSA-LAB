#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtEnd(struct Node* last, int data) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return last;
    }
    
    newNode->data = data;

     if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        
        newNode->next = last->next;
     
        last->next = newNode;
      
        last = newNode;
    }
    
    return last;
}


void displayList(struct Node* last) {
    if (last == NULL) {
        printf("The list is empty.\n");
        return;
    }

 
    struct Node* head = last->next;
    struct Node* temp = head;

    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    struct Node* last = NULL;

    
    last = insertAtEnd(last, 10);
    last = insertAtEnd(last, 20);
    last = insertAtEnd(last, 30);
    last = insertAtEnd(last, 40);


    displayList(last);

    
    if (last != NULL) {
        struct Node* head = last->next;
        struct Node* temp = head;
        struct Node* nextNode;
        
        do {
            nextNode = temp->next;
            free(temp);
            temp = nextNode;
        } while (temp != head);
    }

    return 0;
}
