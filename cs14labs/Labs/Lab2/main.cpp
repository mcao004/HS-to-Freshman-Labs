// Marvin Cao
// Alan Tran

#include <iostream>
#include "IntList.h"

using namespace std;

int main() {
    
    IntList test;
    
    if (test.empty())
    {
        cout << "empty" << endl;
    }
    
    test.push_front(0);
    
    cout << test << endl;
    
    test.push_back(1);
    test.push_back(12);
    test.push_back(-532);
    test.push_front(19);
    test.push_front(8);
    
    test.printReverse();
    cout << endl;
    //Should be (8, 19, 1, 12, -532)
    
    test.pop_front();
    cout << test << endl;
    
    test.pop_back();
    cout << test << endl;
    
    if (!test.empty())
    {
        cout << "not empty" << endl;
    }
    
    cout << test;
}