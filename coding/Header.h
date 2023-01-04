#pragma once
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

/* Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you 
cannot use additional data structures?
*/

// One Way

//using hashset to insert each char, if the char was found in hashset, return 
bool isUnique(string data) {
    unordered_set<char> myset;
    for (int i = 0; i < data.size(); i++) {
        if (myset.find(data[i]) != myset.end()){
            return 0;
        }
        myset.insert(data[i]);
    }
    return 1;
}


int main()
{
    string data = "unique";
    
    if (isUnique(data)) {
        cout << "Yes";
    }
    cout << "No";
    return 0;
}