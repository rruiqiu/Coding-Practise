#pragma once
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>
#include <stdio.h>
#include <math.h>

using namespace std;

class Hashtable {
public:
	bool isUnique(string data);
	bool checkPermutation(string a, string b);
	string urlify(string& a, int length);
	bool checkpalindrom(string a);
	bool oneAway(string a, string b);
};