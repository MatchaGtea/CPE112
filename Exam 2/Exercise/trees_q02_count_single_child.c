/*
Topic: Trees
Question 2: Count nodes with exactly one child

What to do:
- Complete createNode and freeTree.
- countSingleChildNodes is the recursive function.
- Count a node only when it has exactly one child.
- Do not use global variables.

Example tree:
    10
   /  \
  5    20
   \     \
    8     25

Example output:
2
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

/*
Create a new node
*/
struct Node* createNode(int value)
{
    // TODO
    return NULL;
}

/*
Count nodes with exactly one child
*/
int countSingleChildNodes(struct Node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int count = 0;

    if ((root->left != NULL && root->right == NULL) ||
        (root->left == NULL && root->right != NULL))
    {
        count = 1;
    }

    return count +
           countSingleChildNodes(root->left) +
           countSingleChildNodes(root->right);
}

/*
Free tree memory
*/
void freeTree(struct Node* root)
{
    // TODO
}

int main()
{
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->right = createNode(8);
    root->right->right = createNode(25);

    printf("%d\n", countSingleChildNodes(root));

    freeTree(root);

    return 0;
}
