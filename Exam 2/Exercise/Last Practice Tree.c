#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *insert(Node *root ,int key){
    if(root == NULL){
        Node *newNode = malloc(sizeof(Node));
        newNode -> data = key;
        newNode -> left = NULL;
        newNode -> right = NULL;
        return newNode;
    }
    if(root->data > key){
        root->left = insert(root->left,key);
    }else if(root->data < key){
        root->right = insert(root->right , key);
    }
    return root;
}

void FindSuccessor(Node *root , int key){
    if(root == NULL) return ;
    Node *current = root;
    Node *Successor = NULL;

    while(current != NULL){
    if(current->data > key){
        Successor = current ;
        current = current->left;
    }else{
        current = current->right;
    }
}
    if(Successor == NULL){
        printf("No key");
    }else{
        printf("Successor = %d ", Successor->data);
    }
}

Node* DeleteOneChild(Node *root , int key){
     if(root == NULL) return NULL;

     if(root->data > key){
        root->left = DeleteOneChild(root->left , key);
     }else if (root -> data < key){
        root->right = DeleteOneChild(root->right , key);
     }else{
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        else if(root->left == NULL && root->right == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else return root;
     }
     return root;
}

int CountNode(Node *root){
    int count = 0 ;
    if(root == NULL) return 0;
    if(root->left == NULL && root->right != NULL || root->left != NULL && root->right == NULL){
        count = 1;
    }
    return count + CountNode(root->left) + CountNode(root->right);
}

void Inorder(Node* root){
    if(root == NULL) return;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}

int main(){
    Node *root = NULL;
    //printf("Start");
    root = insert(root, 10);
    //printf("root = %d", root->data);
    root = insert(root, 20);
    root = insert(root, 30);
    Inorder(root);
    printf("\n");
    FindSuccessor(root,20);
}