#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];


void initialize() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
}


void insert(int key) {
    int index = key % SIZE;
    int start = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;

        if (index == start) {
            printf("Hash table is full!\n");
            return;
        }
    }

    hashTable[index] = key;
    printf("%d inserted at index %d\n", key, index);
}


void search(int key) {
    int index = key % SIZE;
    int start = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            printf("%d found at index %d\n", key, index);
            return;
        }

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    printf("%d not found in hash table\n", key);
}

int main() {
    int choice, key;

    initialize();

    while (1) {
        printf("\n1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 3:
                printf("Hash Table:\n");
                for (int i = 0; i < SIZE; i++) {
                    printf("Index %d: %d\n", i, hashTable[i]);
                }
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
