#ifndef function_h
#define function_h

#include <iostream>
#include <math.h>
using namespace std;

class BST{
public:
    BST():Height(0){}
    virtual ~BST() {}
    virtual void insert(const int &) = 0;
    virtual void print() const = 0;
    int height() const { return Height; }// An empty tree has height of 0. A tree with only root node has height of 1.

protected:
    int Height;
};

class ListNode{
    friend class List_BST; //make List_BST a friend

public:
    ListNode(const int &info):key( info ),left( NULL ),right( NULL ) //constructor
    {
    }//end ListNode constructor

private:
    int key;
    ListNode *left;
    ListNode *right;
};//end class ListNode

class List_BST : public BST{
public:
    List_BST()
       : BST(), root(NULL)
    {
    }
    virtual ~List_BST() {}
    virtual void insert(const int &) override;
    virtual void print() const override{
        printIncOrder(root);
    }

private:
    ListNode *root;
    // private member functions
    ListNode* createLeaf(int key) const; //new a ListNode and return its address
    void printIncOrder(ListNode* Ptr) const
    {
        if(Ptr!=NULL)
        {
            printIncOrder(Ptr->left);
            cout<<Ptr->key<<" ";
            printIncOrder(Ptr->right);
        }
    }
};

#endif /* function_h */
