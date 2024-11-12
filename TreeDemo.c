#include<stdio.h>
#include<stdlib.h>

struct Node{
    char data;
    struct Node*  right;
    struct Node*  left;
};

struct Node* createNode(char c){
    struct Node* temp=(struct Node*) malloc(sizeof(struct Node));
    temp->data=c;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}

void postOrderTraversal(struct Node* root){
    if(root!=NULL){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf(" %c - ",root->data);
    }
}

void inOrderTraversal(struct Node* root){
    if(root!=NULL){
        inOrderTraversal(root->left);
        printf(" %c - ",root->data);
        inOrderTraversal(root->right);
    }
}
void preOrderTraversal(struct Node* root){
    if(root!=NULL){
        printf(" %c - ",root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main(){
    struct Node* root;
    root=createNode('A');
    root->left=createNode('B');
    root->right=createNode('C');
    root->left->left=createNode('D');
    root->left->right=createNode('E');
    printf("\nThe InOrder(Left Root Right) Traversal:");
    inOrderTraversal(root);
    printf("\nThe PreOrder(Root Left Right) Traversal:");
    preOrderTraversal(root);
    printf("\nThe Post Order(Left Right Root) Traversal:");
    postOrderTraversal(root);
}