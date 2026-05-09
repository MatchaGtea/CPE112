#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;

Node* insert(Node *root , int key){
    if(root == NULL){
        Node *newNode = malloc(sizeof(Node));
        newNode->data = key;
        newNode->left = NULL ; newNode -> right = NULL;
        return newNode;
    }
    if(root->data > key){
        root->left = insert(root->left , key);
    }else if (root->data < key){
        root->right = insert(root->right , key);
    }
    return root;
}

void FindSuccessor(Node* root , int key){
    if(root == NULL) return;
    Node* current = root;
    Node* successor = NULL;
    while(current != NULL){
        if(current -> data > key){
            successor = current;
            current = current->left;
        }else{
            current = current -> right;
        }
    }
    if(successor == NULL){
        printf("No key");
    }else{
        printf("%d",successor->data);
    }

}

int countNode(Node*root){
    int count = 0;
    if(root = NULL) return 0;
    if(root->left != NULL && root->right == NULL || root->left == NULL && root->right !=NULL ) count =1 ;

    return count + countNode(root->left) + countNode(root ->right);

}

Node* DeleteOneChild(Node *root , int key){
    if(root == NULL) return NULL;
     if(root->data > key){
        root -> left = DeleteOneChild(root->left , key);
     }else if(root -> data < key){
        root->right = DeleteOneChild(root->right, key);
     }else{
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }else if(root->left == NULL && root->right != NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }else return root;
     }
     return root;
}

void Inorder(Node* root){
    if(root == NULL) return ;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}



int main(){
    Node *main = NULL;
    main = insert(main , 20);
    main = insert(main , 10);
    main = insert(main , 30);
    printf("Inorder : ");
    Inorder(main);
    printf("\nSuccessor : ");
    FindSuccessor(main,10);
    return 0;    
}
