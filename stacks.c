#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node , *temp, *top = NULL;

int count(){
    int c = 0;
    struct Node *temp = top;
    while (temp != NULL){
        temp = temp->next;
        c++;
    }
    return c;
}

int isEmpty(){
    return top == NULL;
}

int isFull(){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL){
        return 1; 
    }else{
        return 0;
    }
}

void push(){
    int x;
    printf("Enter the data: ");
    scanf("%d", &x);

    if (isFull()){
        printf("Stack Overflow!\n");
    } else {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL){
            printf("Memory allocation failed!\n");
            return;
        }
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        printf("%d is pushed successfully\n", x);
    }
}

void pop(){
    if (isEmpty()){
        printf("Stack Underflow!\n");
    } else {
        struct Node *temp = top;
        printf("%d popped successfully\n", temp->data);
        top = top->next;
        free(temp);
    }
}

void peek(){ 
    if (isEmpty()){
        printf("Stack Underflow!\n");
    } else {
        printf("The data at top of stack is: %d\n", top->data);
    }
}

void display(){
    if (isEmpty()){
        printf("Stack is empty.\n");
        return;
    }

    temp = top;
    printf("Elements in Stack:\n");
    while (temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void search(){
    if (isEmpty()){
        printf("Stack is empty!\n");
        return;
    }

    temp = top;
    int value, c = 0;
    int found = 0;

    printf("Enter the data: ");
    scanf("%d", &value);

    while (temp != NULL){
        c++;
        if (temp->data == value){
            printf("%d is present at position %d\n", value, c);
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (!found){
        printf("%d is not present in the stack\n", value);
    }
}

int main(){

    int n;
    while (1){
        printf("\n---Stack Operations---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Count\n");
        printf("6. Search\n");
        printf("7. Exit\n\n");
        printf("Enter a value: ");
        scanf("%d", &n);
        
        switch (n){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("The no. of nodes in linked list are: %d\n", count());
                break;
            case 6:
                search();
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
