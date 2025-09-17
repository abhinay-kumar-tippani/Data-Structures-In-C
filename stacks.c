#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *top=NULL;

int count(){
    int count=0;
    struct Node *temp=top;
    while (temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}

int isEmpty(){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp==NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(){
    int x;
    printf("Enter the data: ");
    scanf("%d", &x);

    if(isFull()){
        printf("Stack Overflow!\n");
    }else{
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data=x;
        newNode->next=top;
        top=newNode;
        printf("%d is pushed successfully\n", x);
    }
}

void pop(){
    if (isEmpty()){
        printf("Stack Underflow!");
    }else{
        struct Node *temp = top;
        printf("%d popped successfully", temp->data);
        top = top->next;
        free(temp);
    }
}

void peek(){ //returns head data
    printf("The data at top of stack is: %d\n", top->data);
}

void display(){
    struct Node *temp = top;
    int i=1;
    while (temp!=NULL){
        printf("Data at %d is %d\n", i, temp->data);
        temp=temp->next;
        i++;
    }
}


void search(){
    struct Node *temp=top;
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    for (int i = 1; i < pos; i++){
        temp=temp->next;
    }

    printf("The data at %d is %d\n", pos, temp->data);
}

int main(){

    int n;
    while (1){
        
    printf("\n\n1. Push\n");
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
        printf("The no.of Nodes in Linked List are: %d\n", count());
        break;
    
        case 6:
        search();
        break;

        default:
        exit(0);
        }
    }
    return 0;
}