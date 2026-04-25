#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    const char *name;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(const char *name){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->name = name;
    newNode->left = newNode->right = NULL;
    return newNode;
} /* allocate node and set children to NULL */

Node *buildTree(void){
    Node* Motherboard = createNode("Motherboard");
    Node* CPU_Cooler = createNode("CPU_Cooler");
    Node* GPU = createNode("GPU");
    Node* Thermal_Paste = createNode("Thermal_Paste");
    Node* CPU = createNode("CPU");
    Node* PCIe_Riser = createNode("PCIe_Riser");
    Node* Power_Cables = createNode("Power_Cables");
    Node* VRAM = createNode("VRAM");

    Motherboard->left = CPU_Cooler;
    Motherboard->right = GPU;

    CPU_Cooler->left = Thermal_Paste;
    CPU_Cooler->right = CPU;

    GPU->left = PCIe_Riser;
    GPU->right = Power_Cables;

    PCIe_Riser->right = VRAM;

    return Motherboard;
} /* build the fixed PC tree from the handout */

void postorder(Node *root){
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%s ", root->name);
} /* print names in post-order, separated by spaces */

void solve(void){
    Node* root = buildTree();
    postorder(root);
} /* TODO: build tree and call preorder() */

int main(void) {
    solve();
    return 0;
}