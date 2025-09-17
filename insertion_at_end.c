#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head, *second, *third;

void insertAtEnd(struct Node *newNode, int data){
    third->next=newNode;
    newNode->data=data;
    newNode->next=NULL;
}

int main(){

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=NULL;

    struct Node *last = (struct Node*)malloc(sizeof(struct Node));
    
    insertAtEnd(last, 40);
    
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp = head;
    
    while (temp!=NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    
    

return 0;
}