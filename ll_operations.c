#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head, *temp;
    
int count(){
    temp=head;
    int count=0;
    while (temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}

void insert(){
    temp = head;
    int data, pos;
    int c=count();
    printf("Enter the position you want to insert : ");
    scanf("%d", &pos);
    printf("Enter the data at position %d: ", pos);
    scanf("%d", &data);
    temp = head;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    if(pos==1){
        newNode->next=head;
        head=newNode;
    }
    else if(pos==c+1){
        while (temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=NULL;
    }
    else{
        for (int i = 1; i < pos-1; i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
    printf("%d is inserted at %d successfully\n", data, pos);
}

void delete(){
    struct Node *toDelete;
    temp=head;
    int pos;
    int c=count();
    printf("Enter the position you want to delete : ");
    scanf("%d", &pos);
    temp=head;

    if(pos==1){
        toDelete=head;
        head=head->next;
        free(toDelete);
        printf("Data is deleted at %d successfully\n", pos);
    }
    else if(pos==c){
        for (int i = 1; i < pos-1; i++){
            temp=temp->next;
        }
        toDelete=temp->next;
        temp->next=NULL;
        free(toDelete);
        printf("Data is deleted at %d successfully\n", pos);
    }
    else if (pos>c){
        printf("Invalid Position, cannot delete");
    }
    else{
        for (int i = 1; i < pos-1; i++){
            temp=temp->next;
        }
        toDelete=temp->next;
        temp->next=toDelete->next;
        free(toDelete);
        printf("Data is deleted at %d successfully\n", pos);
    }

}

void display(){
    if(head==NULL){
        printf("Linked List is Empty\n");
    }
    else{
        temp=head;
        int i=1;
        while (temp!=NULL){
            printf("Data at %d is %d\n", i, temp->data);
            temp=temp->next;
            i++;
        }
    }
    
}

void search(){
    temp=head;
    int pos;
    printf("Enter the the position: ");
    scanf("%d", &pos);
    for (int i = 1; i < pos; i++){
        temp=temp->next;
    }
    printf("The data at %d is %d\n", pos, temp->data);
    
}

int main(){
    int n;
    while (1){
        
    printf("\n\n1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Count\n");
    printf("5. Search\n");
    printf("6. Exit\n\n");
    printf("Enter a value: ");
    scanf("%d", &n);
    
    switch (n){
    case 1:
        insert();
        break;
        
        case 2:
        delete();
        break;
        
        case 3:
        display();
        break;
        
        case 4:
        printf("The no.of Nodes in Linked List are: %d\n", count());
        break;

        case 5:
        search();
        break;
    
        default:
        exit(0);
        }
    }

return 0;
}