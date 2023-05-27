#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Node* buildTree(int* inorder, int* postorder, int inorder_start, int inorder_end){
     if(inorder_start > inorder_end) return NULL;
     static int post_idx = -1;
     if(post_idx == -1) post_idx = inorder_end;

     Node* tree_node = (Node*)malloc(sizeof(Node));
     tree_node->data = postorder[post_idx--];
     tree_node->left = NULL;
     tree_node->right = NULL;
     if(inorder_start == inorder_end) return tree_node;

     int in_idx;
     for(in_idx = inorder_start; in_idx <= inorder_end; in_idx++)
        if(inorder[in_idx] == tree_node->data) break;

     tree_node->right = buildTree(inorder, postorder, in_idx+1, inorder_end);
     tree_node->left = buildTree(inorder, postorder, inorder_start, in_idx-1);

     return tree_node;
}

void showPreorder(Node* root){
    printf("%d ", root->data);
    if(root->left) showPreorder(root->left);
    if(root->right) showPreorder(root->right);
}
