#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head, *last, *temp;



void insert(int pos, int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    int count=0;
    temp=head;
    while (temp!=NULL){
        temp=temp->next;
        count++;
    }
    
    if(pos==1){
        newNode->next=head;
        head=newNode;
    }
    else if(pos>count){
        temp=head;
        while (temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=NULL;
    }
    else{
        temp=head;
        for (int i = 1; i < pos-1; i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
    
}

void traversal(){
    temp=head;
    while (temp!=NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void delete(int pos){
    struct Node *toDelete;
    int count = 0;
    temp=head;
    while (temp!=NULL){
        temp=temp->next;
        count++;
    }
    
    if(pos==1){
        toDelete=head;
        head=head->next;
        free(toDelete);
    }
    else if (pos==count){
        temp=head;
        for (int i = 1; i < pos-1; i++){
            temp=temp->next;
        }
        toDelete=temp->next;
        temp->next=NULL;
        free(toDelete);
    }
    else{
        temp=head;
        for (int i = 1; i < pos-1; i++){
            temp=temp->next;
        }
        toDelete=temp->next;
        temp->next=toDelete->next;
        free(toDelete);
    }
    
}

void display(){
    temp = head;
    int count=0;
    while (temp!=NULL){
        temp=temp->next;
        count++;
    }
    printf("No.of Nodes: %d\n",count);
    
}

void main(){

    head = (struct Node*)malloc(sizeof(struct Node));
    last = (struct Node*)malloc(sizeof(struct Node));
    temp = (struct Node*)malloc(sizeof(struct Node));

    head->data=10;
    head->next=last;

    last->data=20;
    last->next=NULL;

    traversal();
    display();
    printf("---\n");
    insert(3, 30);
    traversal();
    display();
    printf("---\n");
    printf("After delete:\n");
    delete(3);
    traversal();
    display();
    printf("---\n");
    printf("After delete:\n");
    delete(1);
    traversal();
    display();
   
}