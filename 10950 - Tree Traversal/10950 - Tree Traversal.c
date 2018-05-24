#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void inorder(Node *root) {
    if(root->left) inorder(root->left);
    printf("%d ", root->data);
    if(root->right) inorder(root->right);
}
void postorder(Node *root) {
    if(root->left) postorder(root->left);
    if(root->right) postorder(root->right);
    printf("%d ", root->data);
}
