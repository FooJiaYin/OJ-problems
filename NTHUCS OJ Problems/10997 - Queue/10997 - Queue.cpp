#include <iostream>
#include "function.h"
using namespace std;

List_queue::List_queue(): head{NULL}, tail{NULL} {}

List_queue::~List_queue() {
    delete [] head;
}

void List_queue::enqueue(const int& value) {
    if(head==NULL) {
        head = new ListNode{value};
        tail = head;
    }
    else {
        tail->nextPtr = new ListNode{value};
        tail = tail->nextPtr;
    }
}

void List_queue::dequeue() {
    if(head) {
        ListNode *temp = head;
        head = head->nextPtr;
        delete temp;
    }
}

void List_queue::print() {
    if(head) {
        for(ListNode *temp = head; temp != tail; temp = temp->nextPtr) {
            cout << temp->data << " ";
        }
        cout << tail->data;
    }
}