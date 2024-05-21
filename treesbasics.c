#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *Node(int val) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void inorder(struct node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("-> %d", root->data);
    inorder(root->right);
}

void preorder(struct node* root) {
    if (root == NULL)
        return;

    printf("-> %d", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("-> %d", root->data);
}

struct node *leftInsertion(struct node *root, int val) {
    if (root == NULL)
        return Node(val);

    root->left = leftInsertion(root->left, val);
    return root;
}

struct node *rightInsertion(struct node *root, int val) {
    if (root == NULL)
        return Node(val);

    root->right = rightInsertion(root->right, val);
    return root;
}

int main() {
    int val;

    printf("Enter the root node value: ");
    scanf("%d", &val);
    struct node *root = Node(val);

    printf("Enter the left value: ");
    int val2;
    scanf("%d", &val2);
    leftInsertion(root, val2);

    printf("Enter the right value: ");
    int val3;
    scanf("%d", &val3);
    rightInsertion(root, val3);

    printf("Enter the right node's right value: ");
    int val4;
    scanf("%d", &val4);
    rightInsertion(root->right, val4);

    printf("Enter the left node's left value: ");
    int val5;
    scanf("%d", &val5);
    leftInsertion(root->left, val5);

    printf("\nThe inorder traversal is: \n");
    inorder(root);

    printf("\nThe preorder traversal is: \n");
    preorder(root);

    printf("\nThe postorder traversal is: \n");
    postorder(root);

    return 0;
}


// Tree traversal in C
/*
#include <stdio.h>
#include <stdlib.h>

struct node {
  int item;
  struct node* left;
  struct node* right;
};

// Inorder traversal
void inorderTraversal(struct node* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d ->", root->item);
  inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal(struct node* root) {
  if (root == NULL) return;
  printf("%d ->", root->item);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(struct node* root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ->", root->item);
}

// Create a new Node
struct node* createNode(value) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->item = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

// Insert on the left of the node
struct node* insertLeft(struct node* root, int value) {
  root->left = createNode(value);
  return root->left;
}

// Insert on the right of the node
struct node* insertRight(struct node* root, int value) {
  root->right = createNode(value);
  return root->right;
}

int main() {
  struct node* root = createNode(1);
  insertLeft(root, 2);
  insertRight(root, 3);
  insertLeft(root->left, 4);

  printf("Inorder traversal \n");
  inorderTraversal(root);

  printf("\nPreorder traversal \n");
  preorderTraversal(root);

  printf("\nPostorder traversal \n");
  postorderTraversal(root);
}
*/