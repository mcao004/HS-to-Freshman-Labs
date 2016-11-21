//sean richardson
// Marvin Cao
#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <string>
#include <stdexcept>

#define MAX_SIZE 20

using namespace std;

template<typename T>
class stack
{
    private:
    T data[MAX_SIZE];
    unsigned size;
    
    public:
    stack(); //: constructs an empty stack.
    void push(T val); //: inserts a new element (val) of type T (T could be integer or string) into the data. If the data array is full, this function should throw an overflow_error exception with error message "Called push on full stack.".
    void pop(); //: removes the last element from data. If the data array is empty, this function should throw an outofrange exception with error message "Called pop on empty stack.".
    T top(); //: returns the top element of stack (last inserted element). If stack is empty, this function should throw an underflow_error exception with error message "Called top on empty stack.".
    bool empty(); //: returns true if the stack is empty otherwise it returns false
    
};

template<typename T>
stack<T>::stack()
    : data(), size(0)
{}

template<typename T>
void stack<T>::push(T val)
{
    if(this->size < MAX_SIZE)
    {
       data[size] = val;
       size++;
    }
    else
    {
       throw overflow_error("Called push on full stack."); 
    }
}

template<typename T>
void stack<T>::pop()
{
    if(this->size == 0)
    {
        throw out_of_range("Called pop on empty stack.");
    }
    else
    {
        this->size--;
    }
    return;
}

template<typename T>
T stack<T>::top()
{
    if(this->size == 0)
    {
        throw underflow_error("Called top on empty stack.");
    }
    else
    {
        return data[size-1];
    }
}

template<typename T>
bool stack<T>::empty()
{
    return size <= 0;
}




#endif //__STACK_H__