// Marvin Cao
// Salman Bana
// Steven Nguyen

#include <iostream>
#include <algorithm>
#include "PrintJob.h"
#include "Heap.h"

using namespace std;

Heap::Heap() 
:numItems(0)
{
    for(unsigned i = 0; i < MAX_HEAP_SIZE; ++i)
    {
        arr[i] = 0;
    }
}

void Heap::enqueue(PrintJob* pj) {
    if (numItems != MAX_HEAP_SIZE) {
        if(!arr[0]) { // if empty
            arr[numItems] = pj;
            numItems++;
        } else { // if not empty
            int x = numItems;
            while(x > 0 && arr[(x-1)/2]->getPriority() < pj->getPriority()) { // priority of parent < ours
                arr[x] = arr[(x-1)/2]; // move parent down to where the last item would be
                x = (x-1)/2;
            }
            arr[x] = pj;
            ++numItems;
        }
    }
}

void Heap::dequeue() {
    if(numItems != 0)
    {
        //cout << "dequeueing" << endl;
        if(numItems == 1) {
            delete arr[0];
            arr[0] = 0;
            numItems--;
            return;
        }
        
        delete arr[0];
        arr[0] = arr[numItems - 1];
        arr[numItems - 1] = 0;
        numItems--;
        
        trickleDown(0);
        trickleDown(0);
    }
    
}

PrintJob* Heap::highest() {
    if(arr[0] != 0)
    {
        return arr[0];
    }
    
    return 0;
}

void Heap::print() {
    if(arr[0] != 0)
    {
        cout << "Priority: " << arr[0]->getPriority() 
            << ", Job Number: " << arr[0]->getJobNumber() 
            << ", Number of Pages: " << arr[0]->getPages() << endl;
    }
}

void Heap::trickleDown(int i) { // Put the highest priority child into the hole identified by i
    // if it has both children
    if(2*i+2 >= MAX_HEAP_SIZE || i < 0)
    {
        return;
    }
    //cout << "TrickleDown" << endl;
    if (arr[2*i+1] && arr[2*i+2] && arr[i]->getPriority() > arr[2*i+1]->getPriority() && arr[i]->getPriority() > arr[2*i+2]->getPriority()) {
        //cout << "Path 0" << endl;
        return;
    } else if (arr[2*i+1] && arr[2*i+2] && arr[2*i+1]->getPriority() < arr[2*i+2]->getPriority()) {
        //cout << "Path 1" << endl;
        swap(arr[i], arr[2*i+2]);
        trickleDown(2*i+2);
    } else if (arr[2*i+1] && arr[2*i+2] && arr[2*i+1]->getPriority() >= arr[2*i+2]->getPriority()) {
        //cout << "Path 2" << endl;
        swap(arr[i], arr[2*i+1]);
        trickleDown(2*i+1);
    } else if (arr[2*i+1]) { // one child in left
        //cout << "Path 3" << endl;
        swap(arr[i], arr[2*i+1]);
        trickleDown(2*i+1);
    } 
    
    
    // no children or is the highest priority
    return;
}