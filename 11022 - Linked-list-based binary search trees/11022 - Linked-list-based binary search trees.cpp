#include "function.h"

void List_BST::insert(const int & info) {
    if(root==NULL) {
        root = createLeaf(info);
        Height = 1;
    }
    else {
        int height_count = -1;
        ListNode *target = root;
        while(1) {
            height_count++;
            if(info < target->key) {
                if(target->left) target = target->left;
                else target->left = createLeaf(info);
            }
            else if(info > target->key) {
                if(target->right) target = target->right;
                else target->right = createLeaf(info);
            }
            else break;
        }
        Height = (height_count > Height)? height_count : Height;
    }
}

ListNode* List_BST::createLeaf(int key) const {
    ListNode *newLeaf = new ListNode(key);
    return newLeaf;
}

/* ** Do not write this **
while(1) {
    if(info < target->key) target = target->left;
    else if(info > target->key) target = target->right;
    else break;
}
target = createLeaf(info); //this address will not be saved!!
*/

