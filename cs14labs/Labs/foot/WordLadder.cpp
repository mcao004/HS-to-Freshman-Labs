
#include <iostream>
#include <fstream>
#include <stack>
#include <list>
#include <string>
#include <queue>
#include "WordLadder.h"

using namespace std;

/* Passes in the name of a file that contains a dictionary of 5-letter words.
       Fills the list (dict) with the words within this file. 
       If the file does not open for any reason or if any word within the file
       does not have exactly 5 characters, this function should output an
       error message and return.
    */
WordLadder::WordLadder(const string & s)
{
    ifstream Dictionary;
    string word;
    
    Dictionary.open(s.c_str());
    
    if (!Dictionary.is_open()) {
      cout << "Error: Could not open file: "<< s << endl;
      return; // 1 indicates error
    }
    
    while(Dictionary.good())
    {
        Dictionary >> word;
        if (word.size() != 5)
        {
            cout << "Error: Not a 5 character word" << endl;
            return;
        }
        dict.push_back(word);
    }
    
    Dictionary.close();
}

 /* Passes in two 5-letter words and the name of an output file.
       Outputs to this file a word ladder that starts from the first word passed in
       and ends with the second word passed in.
       If either word passed in does not exist in the dictionary (dict),
       this function should output an error message and return.
       Otherwise, this function outputs to the file the word ladder it finds or outputs
       to the file, the message, "No Word Ladder Found!!"
    */
void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile)
{
    ofstream outFS;
    outFS.open(outputFile.c_str());
    
    if(!outFS.is_open())
    {
        cout << "Error: could not open output file: " << outputFile << endl;
        return;
    }
    
    
    queue<stack<string> > q;
    stack<string> s;
    list<string>::iterator wordIt;
    list<string>::iterator tempWord;
    string top;
    bool found1 = false; 
    bool found2 = false;
    
    // check that start and end are inside dict
    for (wordIt = dict.begin(); wordIt != dict.end(); ++wordIt)
    {
        if (start.compare(*wordIt) == 0)
            found1 = true; // found start
        if (end.compare(*wordIt) == 0)
            found2 = true; // found end
    }
    if (!found1 || !found2) // if one of the two is not found
    {
        cout << "Error: could not find at least one of the words." << endl;
    }
    
    s.push(start);
    q.push(s);
    
    while(!q.empty())
    {
        top = q.front().top(); // content(string) of the content(stack<string>) of the queue
        
        for (wordIt = dict.begin(); wordIt != dict.end(); ++wordIt) // .end() returns after-the-end iterator
        {
            if (offByOne(top,*wordIt)) // if differs by one character
            {
                stack<string> newStack = q.front(); //copy or reference to same stack?
                newStack.push(*wordIt);
                
                // push onto queue
                q.push(newStack);
                
                if (end.compare(*wordIt) == 0) // if found, done
                {
                    outputStack(newStack, outFS);
                    outFS.close();
                    return;
                }
                
                // remove current word from dict and set back one
                tempWord = wordIt;
                --tempWord;
                dict.remove(*wordIt);
                wordIt = tempWord;
            }
        }
        // dequeue previous stack
        q.pop();
        // exiting the loop has wordIt point to either the end word or the iterator after the list
        
    }
    
    if (q.empty()) // did not find word ladder
    {
        outFS << "No Word Ladder Found!!" << endl;
        outFS.close();
        return;
    }
    outFS.close();
}


void WordLadder::outputStack(stack<string> s, ofstream & outFS)
{
    string word;
    //while(!s.empty())
    //{
        word = s.top();
        s.pop();
        
        if (!s.empty())
            outputStack(s,outFS);
        outFS << word << " ";
        
    //}
}

bool WordLadder::offByOne(string top, string wordIt)
{
    int diff = 0; // # of different letters
    
    for (int i = 0; i < 5; ++i)
    {
        if (top[i] != wordIt[i])
            ++diff;
        if (diff > 1)
            return false;
    }
    
    if (diff == 1)
        return true;
    return false;
}


