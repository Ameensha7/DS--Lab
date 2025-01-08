#include <stdio.h>
#include <stdlib.h>
#define RED 0
#define BLACK 1
struct Node {
    int data;
    int color; 
    struct Node *left, *right, *parent;
};
struct Node *root = NULL;
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = newNode->parent = NULL;
    newNode->color = RED; 
    return newNode;
}
void leftRotate(struct Node **root, struct Node *x) {
    struct Node *y = x->right;
    x->right = y->left;

    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}
void rightRotate(struct Node **root, struct Node *x) {
    struct Node *y = x->left;
    x->left = y->right;

    if (y->right != NULL)
        y->right->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        *root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;

    y->right = x;
    x->parent = y;
}
void fixInsert(struct Node **root, struct Node *node) {
    struct Node *uncle;
    while (node != *root && node->parent->color == RED) {
        if (node->parent == node->parent->parent->left) {
            uncle = node->parent->parent->right;
            if (uncle != NULL && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent; 
            }
            else {
                if (node == node->parent->right) {
                    node = node->parent;
                    leftRotate(root, node);  
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rightRotate(root, node->parent->parent); 
            }
        }
        else {
            uncle = node->parent->parent->left;
            if (uncle != NULL && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rightRotate(root, node); 
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                leftRotate(root, node->parent->parent); 
            }
        }
    }
    (*root)->color = BLACK;
}
void insert(struct Node **root, int data) {
    struct Node *node = createNode(data);
    struct Node *y = NULL;
    struct Node *x = *root;
    while (x != NULL) {
        y = x;
        if (data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    node->parent = y;
    if (y == NULL)
        *root = node;
    else if (data < y->data)
        y->left = node;
    else
        y->right = node;
    fixInsert(root, node);
}
void inOrderTraversal(struct Node *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d (%s) ", root->data, root->color == RED ? "Red" : "Black");
        inOrderTraversal(root->right);
    }
}
int main() {
    int values[] = {20, 15, 25, 10, 5, 1};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        insert(&root, values[i]);
    }

    printf("In-order traversal of the Red-Black Tree:\n");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}

