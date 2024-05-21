#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int arr[MAX], top = -1;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void push(int data) {
    if (top < MAX - 1) {
        arr[++top] = data;
    }
}

int topS() {
    if (top >= 0) {
        return arr[top];
    }
    return -1; // or any other error value
}

void pop() {
    if (top >= 0) {
        top--;
    }
}

bool isEmpty() {
    return top == -1;
}

void inorder(struct node* root) {
    struct node* current = root;

    while (current != NULL || !isEmpty()) {
        while (current != NULL) {
            push((int)current); // Push the pointer value onto the stack
            current = current->left;
        }

        current = (struct node*)topS(); // Pop the pointer value
        pop();

        printf("%d ", current->data);

        current = current->right;
    }
}

int main() {
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    inorder(root);
    return 0;
}
