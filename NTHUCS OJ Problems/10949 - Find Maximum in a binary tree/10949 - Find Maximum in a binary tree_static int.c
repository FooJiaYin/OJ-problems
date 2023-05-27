#include stdio.h
#include stdlib.h
#include function.h

int maxValue(Node tree){
    static int max;
    if(tree-data  max) max = tree-data;
    if(tree-left) maxValue(tree-left);
    if(tree-right) maxValue(tree-right);
    return max;
}
