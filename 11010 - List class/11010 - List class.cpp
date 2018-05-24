#include <iostream>
#include "function.h"
using namespace std;

OWList::OWList(): firstPtr{NULL}, lastPtr{NULL} {}

OWList::~OWList() {
    if(firstPtr) delete [] firstPtr;
}

void OWList::insertAtFront( const int &value ) {
    ListNode *temp = new ListNode{value};
    temp->nextPtr = firstPtr;
    if(firstPtr==NULL) lastPtr = temp;
    firstPtr = temp;
}
void OWList::removeFromFront() {
    if(firstPtr) {
        ListNode *temp = firstPtr;
        firstPtr = firstPtr->nextPtr;
        if(lastPtr==temp) lastPtr = NULL;
        delete temp;
    }
}

bool OWList::isEmpty() const {
    if(firstPtr) return false;
    else return true;
}

void OWList::print() const {
    if(firstPtr) {
        for(ListNode *temp = firstPtr; temp!=lastPtr; temp = temp->nextPtr) {
            cout << temp->data << " ";
        }
        cout << lastPtr->data;
    }
    
}
void TWList::insertAtBack( const int &value ) {
    if(firstPtr) {
        lastPtr->nextPtr = new ListNode{value};
        lastPtr = lastPtr->nextPtr;
    }
    else {
        firstPtr = new ListNode{value};
        lastPtr = firstPtr;
    }
}

void TWList::removeFromBack() {
    if(firstPtr) {
        ListNode *temp = lastPtr;
        if(firstPtr==lastPtr) firstPtr = lastPtr = NULL;
        else {
            for(lastPtr = firstPtr; lastPtr->nextPtr!=temp; lastPtr = lastPtr->nextPtr);
            lastPtr->nextPtr = NULL;
        }
        delete temp;
    }
}