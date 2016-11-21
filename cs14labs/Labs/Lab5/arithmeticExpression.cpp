// Marvin Cao
//Jang-Shing Lin SID:861215257
#include "arithmeticExpression.h"
#include <sstream>
#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

arithmeticExpression::arithmeticExpression(const string& express): infixExpression(express), root(0){
}

void arithmeticExpression::buildTree() {
    string postfixExpression = this->infix_to_postfix();
    stack<TreeNode*> s;
    char letter = 'a';
    char c;
    for (unsigned i = 0; i < postfixExpression.size(); ++i )
    {
        c = postfixExpression.at(i);
        if (c == '+' || c == '-' || c == '*' || c == '/') // operator
        {
            TreeNode* newRoot = new TreeNode(c, letter + i);
            // pop twice and set as children
            newRoot->left = s.top();
            s.pop();
            newRoot->right = s.top();
            s.pop();
            // push the new tree onto the stack
            s.push(newRoot);
        } else // operand
        {
            s.push(new TreeNode(c, letter + i));
        }
    }
    root = s.top();
    s.pop();
    // stack should be empty
}

void arithmeticExpression::infix(){
    if(root == 0){
        return;
    }
    infix(root);
}

void arithmeticExpression::infix(TreeNode* nodePtr){
    if(nodePtr){
        if (nodePtr->left != 0 || nodePtr->right != 0)
            cout << "(";
        infix(nodePtr->right);
        cout << nodePtr->data;
        infix(nodePtr->left);
        if (nodePtr->left != 0 || nodePtr->right != 0)
            cout << ")";
    }
    else {
        return;
    }
}

void arithmeticExpression::prefix() {
    if(root == 0){
        return;
    }
    else{
        prefix(root);
    }
}

void arithmeticExpression::prefix(TreeNode* nodePtr) {
    if (nodePtr){
        cout << nodePtr->data;
        prefix(nodePtr->right);
        prefix(nodePtr->left);
    }
    else {
        return;
    }
}

void arithmeticExpression::postfix() {
    if(root == 0){
        return;
    }
    postfix(root);
}

void arithmeticExpression::postfix(TreeNode* nodePtr) {
    if (nodePtr){
        postfix(nodePtr->right);
        postfix(nodePtr->left);
        cout << nodePtr->data;
    }
    else {
        return;
    }
}

void arithmeticExpression::visualizeTree(ofstream & outFS, TreeNode* node){
    if(!node){
        return;
    }
    
    outFS << "\t" << node->key << "[" 
        << "color = cyan, style = filled, label =" 
        << "\"" << node->data << "\"" 
        << "];" << "\n";
    
    visualizeTree(outFS, node->left);
    visualizeTree(outFS, node->right);
    
    if (node->left != 0)
        outFS << "\t" << node->key << "->" << node->left->key << ";\n";
    if (node->right != 0)
        outFS << "\t" << node->key << "->" << node->right->key << ";\n";
    return;
}