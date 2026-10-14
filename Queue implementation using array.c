#include<stdio.h>
#include<stdlib.h>
#define size 100
int queue[size];
int F = 0, R = -1;
void enqueue(int data) {
    if(R == size - 1)
        printf("We cannot store new data\n");
    else {
        R++;
        queue[R] == data;
    }
}
void dequeue() {
    if(R < F)
        printf("Underflow error.");
    else {
        printf("Deleted data = %d",queue[F]);
        F++;
    }
    printf("\n");
}
void display() {
    int i;
    if(R < F)
        printf("Queue is empty");
    else {
        for(i = F; i <= R; i++)
            printf("%d",queue[i]);
    }
    printf("\n");
}
void isEmpty() {
    if(R < F)
        printf("Queue is empty");
    else
        printf("Queue is not empty");
    printf("\n");
}
void isFull() {
    if(F == 0 && R == size -1)
        printf("Queue is full");
    else
        printf("Queue is not full");
    printf("\n");
}
int main() {
    int op, data;
    while(1) {
        printf("1.Enqueue 2.Dequeue 3.Display 4.IsEmpty 5.IsFull 6.Exit\n");
        printf("Enter your option : ");
        scanf("%d",&op);
        switch(op) {
            case 1:
            printf("Enter element : ");
            scanf("%d",&data);
            enqueue(data);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            isEmpty();
            break;
            case 5:
            isFull();
            break;
            case 6:
            exit(0);
        }
    }
    return 0;
}
