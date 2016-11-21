// Marvin Cao
// Alan Tran

#include "IntList.h"

using namespace std;

IntList::IntList() 
{
    cout << "Constructor called" << endl;
    dummyHead = new IntNode(0);
    dummyTail = new IntNode(0);
    
    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;
}

IntList::~IntList()
{
    cout << "Destructor called" << endl;
    
    while(dummyHead->next != dummyTail) {
        
        IntNode* temp = dummyHead->next->next;
        delete dummyHead->next;
        dummyHead->next = temp;
    }
    
    delete dummyHead;
    delete dummyTail;
}

void IntList::push_front(int value)
{
    cout << "push_front called" << endl;
    IntNode* newNode = new IntNode(value);
    newNode->prev = dummyHead;
    newNode->next = dummyHead->next;
    dummyHead->next->prev = newNode;
    dummyHead->next = newNode;
}

void IntList::pop_front()
{
    cout << "pop_front called" << endl;
    
    dummyHead->next->next->prev = dummyHead;
    IntNode* temp = dummyHead->next->next;
    delete dummyHead->next;
    dummyHead->next = temp;
}

void IntList::push_back(int value)
{
    
    cout << "push_back called" << endl;
    
    IntNode* newNode = new IntNode(value);
    IntNode* prev = dummyTail->prev;
    newNode->prev = prev;
    newNode->next = dummyTail;
    prev->next = newNode; // error
    dummyTail->prev = newNode;
    
}

void IntList::pop_back()
{
    cout << "pop_back called" << endl;
    
    dummyTail->prev->prev->next = dummyTail;
    IntNode* temp = dummyTail->prev->prev;
    delete dummyTail->prev;
    dummyTail->prev = temp;
}

bool IntList::empty() const
{
    cout << "empty called" << endl;
    
    if (dummyHead->next == dummyTail)
        return true;
    else
        return false;
}

ostream & operator<<(ostream &out, const IntList &rhs)
{
    cout << "<< called" << endl;
    
    IntNode* currNode = (rhs.dummyHead)->next;
    
    while(currNode != (rhs.dummyTail)) 
    {
        if (currNode->next == rhs.dummyTail)
        {
            out << currNode->data;
        }
        else
            out << currNode->data << " ";
        currNode = currNode->next;
    }
    
    return out;
}

void IntList::printReverse() const
{
    cout << "printReverse called" << endl;
    
    IntNode* currNode = dummyTail->prev;
    while(currNode != dummyHead)
    {
        if (currNode->prev == dummyHead)
        {
            cout << currNode->data;
        }
        else
            cout << currNode->data << " ";
        currNode = currNode->prev;
    }
}

