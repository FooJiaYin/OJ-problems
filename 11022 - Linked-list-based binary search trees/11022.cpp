#include <iostream>
#include <string.h>
#include "function.h"
using namespace std;

void BSTManipulator(BST& bstobj, char cmd ){
    int n;
    if (cmd == 'I') {
        cin >> n;
        bstobj.insert(n);
    }else if (cmd == 'H'){
        cout << bstobj.height() << endl;;
    }else if (cmd == 'P'){
        bstobj.print();
        cout << endl;
    }
}
int main(){
    List_BST bst;
    char cmd;

    while (cin >> cmd)
        BSTManipulator(bst, cmd);

    return 0;
}
