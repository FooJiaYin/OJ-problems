#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int maxValue(Node *tree){
    int left_max=0, right_max=0, max = tree->data;
    if(tree->left) left_max = maxValue(tree->left);
    if(tree->right) right_max = maxValue(tree->right);
    if(left_max > max) max = left_max;
    if(right_max > max) max = right_max;
    return max;
}
