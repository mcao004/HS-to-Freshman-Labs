// Salman Bana
// Marvin Cao

#include <iostream>
#include <vector>
#include <string>
#include <ostream>
#include <stdexcept>
#include <ctime>
#include <cstdlib>

using namespace std;

//Passes in an index of type int and a vector of type T 
//(T could be string, double or int). 
//The function returns the index of the min value starting from 
template <typename T>
unsigned min_index(const vector<T> &vals, unsigned index)
{
    //Initialize two things, a minimum "value" of type T that we compare each "value" in the vector to
    //And the index of said minimum value which we wil be updating throughout the for loop
    unsigned min_index = index;
    T min = vals.at(index);
    //Start at index + 1 since we initialize the previous variables to index
    for(unsigned i = index + 1; i < vals.size(); ++i) {
        if(vals.at(i) < min) {
        //Update both min and min_index if less than min 
            min = vals.at(i);
            min_index = i;
        }
    }
    //Return the newly updated min_index
    return min_index;
    
}

//Passes in a vector of type T and 
//sorts them based on the selection sort method. 
//This function should utilize the min_index function 
//to find the index of the min value in the unsorted portion of the vector.
template <typename T>
void selection_sort(vector<T> &vals)
{
    unsigned mi; // min index
    T temp;
    for (unsigned i = 0; i < vals.size(); ++i)
    {
        mi = min_index(vals, i); // get the min value
        // swapping
        temp = vals.at(i);
        vals.at(i) = vals.at(mi);
        vals.at(mi) = temp;
    }
    return;
}

template <typename T>
ostream & operator<<(ostream &out, vector<T> &vals) 
{
    for(unsigned i = 0; i < vals.size(); ++i) {
        out << vals.at(i) << " ";
    }
    out << endl;
    return out;
}

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

char getChar(vector<char> vals, int index)
{
    try{
        if(index < 0 || index >= static_cast<int>(vals.size())) {
            throw out_of_range("out of range exception occured");
        }
        return vals.at(index);
    }
    catch(out_of_range& excpt)
    {
        cout << excpt.what() << endl;
        return '\n';
    }
}



int main()
{
    //A random assortment of words
    vector<string> v1;
    v1.push_back("apple");
    v1.push_back("teammate");
    v1.push_back("person"); 
    v1.push_back("size"); 
    v1.push_back("sizeable"); 
    v1.push_back("comma"); 
    v1.push_back("period"); 
    
    // size 12 with all 50's
    vector<int> v2;
    v2.push_back(12);
    v2.push_back(0);
    v2.push_back(15);
    v2.push_back(56); 
    v2.push_back(-15); 
    v2.push_back(-2);
    v2.push_back(89); 
    v2.push_back(63); 
    
    vector<double> v3;
    v3.push_back(6.04); 
    v3.push_back(17.24);
    v3.push_back(-59);
    v3.push_back(69);
    v3.push_back(0);
    v3.push_back(1.03);
    v3.push_back(5.2);
    v3.push_back(-15.2);
    v3.push_back(18.06); 
    v3.push_back(963); 
    v3.push_back(-53.2);
    
    vector<string> v4;
    
    selection_sort(v1);
    selection_sort(v2);
    selection_sort(v3);
    selection_sort(v4);
    
    cout << "String vector: " << v1;
    cout << "int vector: " << v2;
    cout << "double vector: " << v3;
    cout << "blah" << v4;
    
    //Part B
     srand(time(0));
     vector<char> vals = createVector();
     char curChar = 'a';
     int index;
     int numOfRuns = 5;
     while(--numOfRuns >= 0){
         cout << "Enter a number: " << endl;
         cin >> index;
         curChar = getChar(vals,index);
         cout << curChar << endl;
     }
    return 0;
}