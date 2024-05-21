#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
    int height;
};
struct node* newNode(int key);
int max(int a, int b) {
    return (a > b) ? a : b;
}

int heightT(struct node* n) {
    if (n == NULL)
        return 0;
    return n->height;
}

int balanceF(struct node* root) {
    if (root == NULL)
        return 0;
    return heightT(root->left) - heightT(root->right);
}

struct node* leftRotation(struct node* y) {
    struct node* x = y->right;
    struct node* T = x->left;

    x->left = y;
    y->right = T;

    y->height = max(heightT(y->left), heightT(y->right)) + 1;
    x->height = max(heightT(x->left), heightT(x->right)) + 1;

    return x;
}

struct node* rightRotation(struct node* y) {
    struct node* x = y->left;
    struct node* T = x->right;

    x->right = y;
    y->left = T;

    y->height = max(heightT(y->left), heightT(y->right)) + 1;
    x->height = max(heightT(x->left), heightT(x->right)) + 1;

    return x;
}

struct node* insertNode(struct node* root, int data) {
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);
    else
        return root; // Duplicate data is not allowed in BST

    root->height = 1 + max(heightT(root->left), heightT(root->right));
    int bf = balanceF(root);
    
    if (bf > 1 && data < root->left->data)
        return rightRotation(root);
         
    if (bf < -1 && data > root->right->data)
        return leftRotation(root);

    if (bf > 1 && data > root->left->data) {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    if (bf < -1 && data < root->right->data) {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

struct node* newNode(int key) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

void inorder(struct node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d -> ", root->data);
    inorder(root->right);
}

int main() {
    struct node* root = NULL;
    root = insertNode(root, 2);
    root = insertNode(root, 1);
    root = insertNode(root, 7);
    root = insertNode(root, 4);
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 8);

    inorder(root);
    printf("\n");

    return 0;
}
