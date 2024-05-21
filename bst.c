#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;

    /* data */
};
struct node* searchNode(struct node *root, int val);
struct node *createNode(int val)
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = val;
    root->left = root->right = NULL;
    return root;
}

struct node *insertNode(struct node *root, int data)
{

    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);

    return root;
}
struct node *inorderLeft(struct node *root)
{
    if (root == NULL)
        return root;
    inorderLeft(root->left);
}
struct node* deleteNode(struct node* root, int val) {
    if (root == NULL) return root;

    struct node* parent = NULL;
    struct node* temp = root;

    // Search for the node to be deleted and keep track of its parent
    while (temp != NULL && temp->data != val) {
        parent = temp;
        if (val < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    // Node to be deleted not found
    if (temp == NULL) return root;

    // Node to be deleted is a leaf node
    if (temp->left == NULL && temp->right == NULL) {
        if (temp == root) { // Special case: deleting the root node
            free(root);
            return NULL;
        }
        if (parent->left == temp) parent->left = NULL;
        else parent->right = NULL;
        free(temp);
        return root;
    }

    // Node to be deleted has only right child
    if (temp->left == NULL) {
        if (temp == root) { // Special case: deleting the root node
            struct node* newRoot = temp->right;
            free(temp);
            return newRoot;
        }
        if (parent->left == temp) parent->left = temp->right;
        else parent->right = temp->right;
        free(temp);
        return root;
    }
 
    // Node to be deleted has only left child
    if (temp->right == NULL) {
        if (temp == root) { // Special case: deleting the root node
            struct node* newRoot = temp->left;
            free(temp);
            return newRoot;
        }
        if (parent->left == temp) parent->left = temp->left;
        else parent->right = temp->left;
        free(temp);
        return root;
    }

    // Node to be deleted has both children
    if (temp->left != NULL && temp->right != NULL) {
        // Find the inorder successor (smallest node in the right subtree)
        struct node* inorderSuccessor = inorderLeft(temp->right);

        // Copy the inorder successor's data to the node to be deleted
        temp->data = inorderSuccessor->data;

        // Recursively delete the inorder successor
        temp->right = deleteNode(temp->right, inorderSuccessor->data);
    }

    return root;
}
struct node *searchNode(struct node *root, int val)
{
    if (root == NULL)
        return root;

    if (root->data == val)
        return root;

    if (val < root->data)
        root->left = searchNode(root->left, val);
    else
        root->right = searchNode(root->right, val);
    return root;
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("-> %d", root->data);
    inorder(root->right);
}

int main()
{
    struct node *root = NULL;
    root = insertNode(root, 1);
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 2);
    printf("the inorder of the tree is  \n");

    inorder(root);
    root = deleteNode(root, 2);
    printf("\n the new inorder is : \n");
    inorder(root);
}