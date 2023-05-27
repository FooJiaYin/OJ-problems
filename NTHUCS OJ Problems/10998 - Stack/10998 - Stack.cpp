#include <iostream>
#include "function.h"
using namespace std;

List_stack::List_stack() {
    head = tail = NULL;
}

List_stack::~List_stack() {
    delete [] head;
}

void List_stack::push(const int & info) {
    if(head) {
        tail->nextPtr = new ListNode(info);
        tail->nextPtr->prevPtr = tail;
        tail = tail->nextPtr;
    } else {
        head = new ListNode(info);
        tail = head;
    }
}

void List_stack::pop() {
    if(tail!=head) {
        tail = tail->prevPtr;
        delete tail->nextPtr;
    } else {
        delete head;
        head = tail = NULL;
    }
}

void List_stack::print() {
    for(ListNode *temp=tail; temp!=head; temp=temp->prevPtr) {
        cout << temp->data << " ";
    }
    if(head) cout << head->data;
}