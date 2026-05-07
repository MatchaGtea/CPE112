#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node *left;
    struct node *right;
}Node;

Node* insert(Node* root, int key){
    if(root == NULL){
        Node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->key = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if(key < root->key){
        root->left = insert(root->left,key);
    }else{
        root->right = insert(root->right,key);
    }
    return root;
}

Node* findMin(Node* root){
    while(root != NULL && root->left != NULL) root = root->left;
    return root;
}



void preorder(Node* root){
    if(root == NULL) return;
    printf("%d ",root->key);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}

void postorder(Node* root){
    if(root == NULL)return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->key);
}
// 10 20 30 , root 20 , suc = 30
void findSuccessor(Node* root , int key){
    Node* current = root;
    Node* successor = NULL;
    while(current != NULL){
        if(current->key > key){
            successor = current;
            current = current->left;
        }else if(current -> key < key){
            current = current->right;
        }else{
            if(current->right != NULL) {
                successor = findMin(current->right);
            }
            break;
        }
    }

    if(current == NULL){
        printf("key not found");
    }else if(successor == NULL){
        printf("No successor");
    }else{
        printf("successor = %d\n",successor->key);
    }
}

int countSingleChildNodes(Node* root){
    if(root == NULL) return 0;

    int count = 0;
    if((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL)){
        count = 1;
    }

    return count 
        + countSingleChildNodes(root->left) + countSingleChildNodes(root->right);
}

Node* deleteOneChile(Node* root , int key){
    if(root == NULL) return NULL;

    if(key < root->key){
        root->left = deleteOneChile(root->left , key);
    }else if(key > root->key){
        root->right = deleteOneChile(root->right, key);
    }else{
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL && root->left != NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }

        return root;
    }
    return root;
}

void solve(int n){
    Node* root = NULL;
    int value;
    for(int i = 0 ;i <n ; i++){
        scanf("%d", &value);
        root = insert(root, value);
    }
    //preorder(root);
    //inorder(root);
    //postorder(root);

    //findMin(root);
    printf("Key = ");
    int Find_successor;
    scanf("%d",&Find_successor);
    findSuccessor(root,Find_successor);
    printf("\n");
}

int main(){
    int n;
    scanf("%d", &n);
    solve(n);
    return 0;
}