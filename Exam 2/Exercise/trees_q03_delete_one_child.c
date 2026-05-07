/*
Topic: Trees
Question 3: BST delete a node with one child

What to do:
- Complete createNode, insert, inorder, and freeTree.
- deleteOneChild is the target BST delete function.
- Use BST properties.
- Return the updated root.
- Print inorder before and after deletion.

Example tree:
       50
      /  \
    30    70
   /     /  \
 20     60   80

Delete:
key = 30

Example output:
Before deletion: 20 30 50 60 70 80
After deletion: 20 50 60 70 80
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value)
{
    // TODO
    return NULL;
}

struct Node* insert(struct Node* root, int value)
{
    // TODO
    return root;
}

struct Node* deleteOneChild(struct Node* root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (key < root->data)
    {
        root->left = deleteOneChild(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteOneChild(root->right, key);
    }
    else
    {
        /*
        Node found
        */

        /*
        Case: Only right child
        */
        if (root->left == NULL && root->right != NULL)
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        /*
        Case: Only left child
        */
        if (root->right == NULL && root->left != NULL)
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        /*
        If node has 0 or 2 children (not expected in this problem)
        */
        return root;
    }

    return root;
}

void inorder(struct Node* root)
{
    // TODO
}

void freeTree(struct Node* root)
{
    // TODO
}

int main()
{
    struct Node* root = NULL;

    /*
    Build the example tree
    */
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Before deletion: ");
    inorder(root);
    printf("\n");

    /*
    Delete node with one child
    */
    root = deleteOneChild(root, 30);

    printf("After deletion: ");
    inorder(root);
    printf("\n");

    freeTree(root);

    return 0;
}
