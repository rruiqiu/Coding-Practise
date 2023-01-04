#pragma once
#include<array> 
#include<iostream>  
#include <utility>
class Bs {
public:
	int iterativeBs(int arr[], int num, int length);
	int recursiveBs(int arr[],int low, int high, int num);
	//int passingbyRef(int& arr); // in C you cant pass the whole array to a pointer
};
