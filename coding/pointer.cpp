//passing by value
#include <iostream>

void swapbyval(int a,int b) {
	int temp = a;
	a = b;
	b = temp;
	std::cout << "in" << a << "&" << b<<std::endl;
}

//passing by reference
void swapbyref(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void cppswapbyref(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}