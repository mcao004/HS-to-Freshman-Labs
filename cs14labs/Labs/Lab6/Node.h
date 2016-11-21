
#ifndef __NODE_H__
#define __NODE_H__

#include <string>

using namespace std;

class Node {
friend class BSTree;
    private:
        Node* left;
        Node* right;
        Node* parent;
        string message;
        int count;
    public:
        // constructor
        Node(string s);
};


#endif