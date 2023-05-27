#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int max = 0;

Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end)
{
    if(max<inorder_end) max = inorder_end;

    if(inorder_start > inorder_end) return NULL;
    static int pre_idx = 0;
    Node *root = (Node*)malloc(sizeof(Node));
    root->data = preorder[pre_idx++];
    root->left = root->right = NULL;
    if(inorder_start == inorder_end) return root;

    int in_idx;
    for(in_idx=0; in_idx<inorder_end; in_idx++)
        if(inorder[in_idx] == root->data) break;
    root->left = buildTree(inorder, preorder, inorder_start, in_idx-1);
    root->right = buildTree(inorder, preorder, in_idx+1, inorder_end);
    return root;
}

void calculateLevelAvg(Node* root)
{
    int read = 0, end = 0, new = 0;
    Node* tree_level[max];
    tree_level[0] = root;
    float average = root->data;
    printf("%.3f ", average);

    while(end < max){ //each loop for each level
        average = 0;
        for(; read<=end; read++) {
            if(tree_level[read]->left) {
                tree_level[++new] = tree_level[read]->left;
                average += tree_level[new]->data;
            }
            if(tree_level[read]->right) {
                tree_level[++new] = tree_level[read]->right;
                average += tree_level[new]->data;
            }        }
        average /= (new-end);
        printf("%.3f ", average);
        end = new;
    }
}
