#include <iostream>
#include "function.h"
using namespace std;

List_queue::List_queue(): head{NULL}, tail{NULL} {};

List_queue::~List_queue() {
    delete [] head;
}

void List_queue::enqueue(const int& value) {
    if(head==NULL) {
        head = new ListNode(value);
        tail = head;
    } else {
        tail->nextPtr = new ListNode(value);
        tail = tail->nextPtr;
    }
}

int List_queue::dequeue() {
    if(head) {
        ListNode *temp = head;
        head = head->nextPtr;
        delete temp;
    }
    return 1;
}

void List_queue::print(std::ostream &output) {
    if(head) {
        for(ListNode *temp = head; temp != tail; temp = temp->nextPtr) {
            output << temp->data << " ";
            //better than cout << temp->data << " ";
        }
        output << tail->data;
        //better than cout << tail->data;
    }
}

ostream &operator<<(std::ostream & output, Queue & source) {
    source.print(output);
    return output;
}
