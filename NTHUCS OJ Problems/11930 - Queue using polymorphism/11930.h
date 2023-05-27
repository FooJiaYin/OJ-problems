#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>

class ListNode
{
    friend class List_queue; //make List_queue a friend

public:
    ListNode( const int &info ) //constructor
    : data( info ), nextPtr( NULL ), prevPtr( NULL )
    {
    } //end ListNode constructor

private:
    int data; //data
    ListNode *nextPtr; // next node in list
    ListNode *prevPtr;
}; //end class ListNode

class Queue{
    friend std::ostream &operator<<(std::ostream &, Queue &);
    public:
        virtual ~Queue() {};
        virtual void enqueue(const int &) = 0;
        virtual int dequeue() = 0;
        virtual void print(std::ostream &output)=0;

};
class List_queue : public Queue{
    public:
        List_queue();
        virtual ~List_queue();
        void enqueue(const int &);
        int dequeue();
        void print(std::ostream &output);
    private:
        ListNode *head;
        ListNode *tail;
};
#endif
