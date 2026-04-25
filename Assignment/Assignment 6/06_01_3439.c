#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} Node;

Node* insert(Node* root, int key) {
    if (root == NULL) {
        Node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->key = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

void solve(int n) {
    Node* root = NULL;
    int value;
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    inorder(root);
}

int main() {
    int n;
    scanf("%d", &n);
    solve(n);
    return 0;
}