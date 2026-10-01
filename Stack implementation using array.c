#include<stdio.h>
#include<stdlib.h>
#define size 50
int stack[size];
int top = -1;
void push(int item) {
    if(top==size-1)
        printf("Stack is overflow.\n");
    else {
        top++;
        stack[top] = item;
    }
}
void pop() {
    int temp;
    if(top==-1)
        printf("Stack is underflow.\n");
    else {
        temp = stack[top];
        top--;
        printf("Popped value = %d\n",stack[top]);
    }
}
void display() {
    int i;
    if(top==-1)
        printf("Stack is empty.\n");
    else {
        printf("Elements of the stack are : ");
        for(i = top; i >= 0; i--)
            printf("%d ",stack[i]);
        printf("\n");
    }
}
void isEmpty() {
    if(top==-1)
        printf("Stack is empty.\n");
    else 
        printf("Stack is not empty.\n");
}
void peek() {
    if(top==-1)
        printf("Stack is underflow.\n");
    else
        printf("Peek value = %d\n",stack[top]);
}
void isFull() {
    if(top==size-1)
        printf("Stack is full.\n");
    else 
        printf("Stack is not full.\n");
}
int main() {
    int op, data;
    while(1) {
        printf("1.Push 2.Pop 3.Display 4. Is Empty 5.Peek 6.Is Full 7.Exit\n");
        printf("Enter your option : ");
        scanf("%d",&op);
        switch(op) {
        case 1:
        printf("Enter element : ");
        scanf("%d",&data);
        push(data);
        break;
        case 2:
        pop();
        break;
        case 3:
        display();
        break;
        case 4:
        isEmpty;
        break;
        case 5:
        peek();
        break;
        case 6:
        isFull();
        break;
        case 7:
        exit(0);
    }
    }
    
}
    
