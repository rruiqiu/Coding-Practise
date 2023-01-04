#include "hashtable.h"
bool Hashtable::isUnique(string data) {
    //unordered_set<char> myset;
    //for (int i = 0; i < data.size(); i++) {
    //    if (myset.find(data[i]) != myset.end()) {
    //        return 0;
    //    }
    //    myset.insert(data[i]);
    //}
    //return 1;

    //bit wise operation
    //int checker = 0;
    //for (int i = 0; i < data.size(); i++) {
    //    int val = data[i] - 'a';
    //    if ((checker & (1 << val)) > 0) { //using checker to store the digiti of each char, if the cooresponding digit of char is appeared before, the and bit operator will give a value greater than zero
    //        return false;
    //    }
    //    checker |= (1<<val);
    //}
    //return 1;

    //not using data structure (brutue force n^2)
    //for (int i = 0; i < data.size(); i++) {
    //    for (int j = i+1; j < data.size(); j++) {
    //        if (data[i] == data[j]) {
    //            return 0;
    //        }
    //    }
    //}
    //return 1;

    // O(n logn) Using Sort then compare lineraily, but remember it will take a lot of space
    sort(data.begin(), data.end());
    for (int i = 0; i < data.size() - 1; i++) {
        if (data[i] == data[i + 1]) {
            return 0;
        }
    }
    return 1;
}

bool Hashtable::checkPermutation(string a, string b) {
    //sort them and compare using O(nlog n)
    //sort(a.begin(), a.end());
    //sort(b.begin(), b.end());
    //for (int i = 0; i < a.size(); i++) {
    //    if (a[i] != b[i]) {
    //        return 0;
    //    }
    //}
    //return 1;
    //hashtable method, insert each element with the num of appearnce
    //in b, if found the corresponding element, delete
    unordered_map<char, int> map;
    for (int i = 0; i < a.size(); i++) {
        map[a[i]] ++;
    }
    for (int i = 0; i < b.size(); i++) {
        map[b[i]] --;
        if (map[b[i]] < 0) {
            return 0;
        }
    }

    return 1;
}
//it's easier to manipulate a string in reverse order
string Hashtable::urlify(string& a, int length) {
    int countlength = length - 1, index = length;
    for (int i = 0; i < length - 1; i++) {
        if (a[i] == ' ') {
            countlength += 2; //notice the space occupied one space, so we only need to increment two for the extra two chars.
        }
    }
    for (int i = index - 1; i >= 0; i--) {
        if (a[i] == ' ') {
            a[countlength] = '0';
            a[countlength - 1] = '2';
            a[countlength - 2] = '%';
            countlength -= 3;
        }
        else {
            a[countlength] = a[i];
            countlength--;
        }
    }

    return a;
}

//palindrome permutation meaning: rearrange the string and if it first equals to the last then palindrome
bool Hashtable::checkpalindrom(string a) {
    //for (int i = 0; i < a.size(); i++) {
    //    if (a[i] >= 65 && a[i] <= 90) {
    //        a[i] = a[i] + 32;
    //    }
    //}
    //int count = 0;
    //sort(a.begin(), a.end());

    //for (int i = 0; i < a.size(); i++) {
    //    if (a[i] >= 97 && a[i] <= 122) {
    //        if (a[i] == a[i + 1]) {
    //            i++;
    //        }
    //        else {
    //            count++;
    //        }
    //        if (count > 1) {
    //            return 0;
    //        }
    //    }
    //}
    //return 1;

    //using hashtable will achieve O(n) time
    //one way is insert each element into a hashtaable and then go back to check if the appearcnce that only one char has one odd number
    //unordered_map<char, int> map;
    //for (int i = 0; i < a.size(); i++) {
    //    if (a[i] >= 97 && a[i] <= 122) {
    //        map[a[i]]++;
    //    }
    //    if (a[i] >= 65 && a[i] <= 90) {
    //        map[a[i] + 32] ++;
    //    }
    //}
    //// only one odd number appeared
    //int countodd = 0;
    //for (auto i : map) {
    //    if (i.second % 2 == 1) { //odd
    //        countodd++;
    //    }
    //    if (countodd > 1) {
    //        return 0;
    //    }
    //}
    //return 1;
     //Another way is to check during the iteration sitll O(n) time though descrease iteration but add conditions for each iteration
    //unordered_map<char, int> map;
    //int countodd = 0;
    //for (int i = 0; i < a.size(); i++) {
    //    if (a[i] >= 97 && a[i] <= 122) {
    //        map[a[i]]++;
    //        if (map[a[i]] % 2 == 1) {
    //            countodd++;
    //        }
    //        else {
    //            countodd--;
    //        }
    //    }
    //    if (a[i] >= 65 && a[i] <= 90) {
    //        a[i] = a[i] + 32;
    //        map[a[i]] ++;
    //        if (map[a[i]] % 2 == 1) {
    //            countodd++;
    //        }
    //        else {
    //            countodd--;
    //        }
    //    }

    //}
    //return countodd > 1 ? 0 : 1;
    // for bitwise way, using bit to record the appearance and then xor to flip.
    // the last bit should have the most bit set equal to 1
    // if the most bit is 1; then its bitwise -1 and the origin is equal to zero

    int bitset = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] >= 97 && a[i] <= 122) {
            bitset = bitset ^ (1 << (a[i] - 97));
        }
        if (a[i] >= 65 && a[i] <= 90) {
            bitset = bitset ^ (1 << (a[i] - 65));
        }
    }
    return ((bitset & (bitset - 1)) == 0);
}

bool Hashtable::oneAway(string a, string b) {
    //possible ways, insert, remove or replace one
    //hash table method, will be a problem if switch the ordr of the string
    //unordered_map<char, int> map;
    //int count=0;
    //for (int i = 0; i < a.size(); i++) {
    //    map[a[i]]++;
    //}
    //for (int i = 0; i < b.size(); i++) {
    //    map[b[i]]--;
    //}
    //for (auto i : map) {
    //    if (i.second != 0) {
    //        count++;
    //    }
    //}
    //if (count > 2) {
    //    return 0;
    //}
    //return 1;

    //check them each one by one

    if (abs(int(a.size() - b.size()) > 1)) {
        return 0;
    }
    if (a.size() > b.size()) {
        int j = 0, count = 0;
        for (int i = 0; i < b.size(); i++) {
            if (a[j] != b[i]) {
                i--;
                count++;
            }
            j++;
            if (count > 1) {
                return 0;
            }
        }

    }
    else if (a.size() < b.size()) {
        int j = 0, count = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[j] != b[i]) {
                i--;
                count++;
            }
            j++;
            if (count > 1) {
                return 0;
            }
        }
    }
    else if (a.size() == b.size()) {
        int count = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                count++;
            }
            if (count > 1) {
                return 0;
            }
        }
    }
    return 1;
}