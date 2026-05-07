/*
Topic: Trees
Question 1: BST in-order successor

What to do:
- Complete the missing BST helpers.
- Find and print the in-order successor of key.
- Do not use arrays.
- Use BST properties only.
- If no successor exists, print "No successor".

Example tree:
50 30 75 20 40 60 90

Example:
key = 40

Example output:
50
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    // TODO: add int data;
    // TODO: add struct Node *left;
    // TODO: add struct Node *right;
};

/*
Create a new BST node
*/
// TODO

/*
Insert into BST
*/
struct Node* insert(struct Node* root, int value)
{
    // TODO
    return root;
}

/*
Find minimum node in a subtree
*/
struct Node* findMin(struct Node* root)
{
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

/*
Find and print in-order successor
*/
void findSuccessor(struct Node* root, int key)
{
    struct Node* current = root;
    struct Node* successor = NULL;

    while (current != NULL)
    {
        if (key < current->data)
        {
            successor = current;
            current = current->left;
        }
        else if (key > current->data)
        {
            current = current->right;
        }
        else
        {
            /*
            Node found
            */
            if (current->right != NULL)
            {
                successor = findMin(current->right);
            }
            break;
        }
    }

    if (current == NULL)
    {
        printf("Key not found\n");
    }
    else if (successor == NULL)
    {
        printf("No successor\n");
    }
    else
    {
        printf("%d\n", successor->data);
    }
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
    struct Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 75);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 90);

    /*
    Example: successor of 40 is 50
    */
    findSuccessor(root, 40);

    freeTree(root);

    return 0;
}
