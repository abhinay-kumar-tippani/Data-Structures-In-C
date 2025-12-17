#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

struct Node *newNode(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
};

struct Node *insert(struct Node *root, int data){
    if(root==NULL){
        return newNode(data);
    }
    if(data<root->data){
        root->left = insert(root->left, data);
    }
    else if(data>root->data){
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(struct Node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root){
    if(root!=NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void main(){
    int n, data;
    printf("Enter no.of nodes: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
    printf("Enter node %d: ", i+1);
    printf("\n");
    scanf("%d", &data);
    root = insert(root, data);
	}
    
	printf("Preorder Traversal: ");
	preorder(root);
	printf("Inorder Traversal: ");
	inorder(root);
	printf("Postorder Traversal: ");
	postorder(root);
}