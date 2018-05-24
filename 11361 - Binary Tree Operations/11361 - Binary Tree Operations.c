#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end)
{
    if(inorder_start > inorder_end) return NULL;
    static int pre_idx = 0;
    Node* root = (Node*)malloc(sizeof(Node));
    root->data = preorder[pre_idx++];
    root->left = NULL;
    root->right = NULL;
    if(inorder_start == inorder_end) return root;
    else {
        /* idx search */
        int in_idx;
        for(in_idx=inorder_start; in_idx<=inorder_end; in_idx++) {
            if(inorder[in_idx] == root->data) break;
        }
        root->left = buildTree(inorder, preorder, inorder_start, in_idx-1);
        root->right = buildTree(inorder, preorder, in_idx+1, inorder_end);

        return root;
    }
}

void showPostorder(Node* root)
{
    if(root->left) showPostorder(root->left);
    if(root->right) showPostorder(root->right);
    printf("%d ", root->data);
    free(root);
}
