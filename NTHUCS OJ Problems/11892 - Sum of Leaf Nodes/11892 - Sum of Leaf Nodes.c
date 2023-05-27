#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end)
{
    if(inorder_start>inorder_end) return NULL;
    static int pre_idx;
    Node *root = (Node*)malloc(sizeof(Node));
    root->data = preorder[pre_idx++];
    root->left = root->right = NULL;
    if(inorder_start<inorder_end){
        int in_idx;
        for(in_idx=inorder_start; in_idx<=inorder_end; in_idx++) {
            if(inorder[in_idx]==root->data) break;
        }
        root->left = buildTree(inorder, preorder, inorder_start, in_idx-1);
        root->right = buildTree(inorder, preorder, in_idx+1, inorder_end);
    }
    return root;
}
void caculateLeafNodesSum(Node* root)
{
    static int times;
    times++;
    if(root->left) caculateLeafNodesSum(root->left);
    if(root->right) caculateLeafNodesSum(root->right);
    if(root->left==NULL && root->right==NULL) {
            if(times==1) printf("%d\n", root->data);
            times--;
            return;
    }
    if(root->right && root->left) root->data = root->left->data + root->right->data;
    else if(root->right) root->data = root->right->data;
    else if(root->left) root->data = root->left->data;
    //printf("%d\n", root->data);
    times--;
    if(times==0) printf("%d\n", root->data);
}

