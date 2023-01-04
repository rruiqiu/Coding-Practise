

//AMD interview question
//apply a binary sort on an sorted array to find a given value index,
//can you do that in recursion way.
//
#include "binaryseach.h"

int Bs::iterativeBs(int arr[], int num, int length) {
	//int length = sizeof(arr) / sizeof(arr[0]); //not working code when passing the size as a parameter buz it's passing the address not the whole array
	int low = 0, high = length - 1;
	while (low <= high) {
		int mid = (low + high) / 2; //50
		if (num == arr[mid]) {
			return mid;
		}
		else if (num < arr[mid]) {
			high = mid - 1; //0 - 49
		}
		else {
			low = mid + 1;
		}
	}
	return -1; // not exist
}

int Bs::recursiveBs(int arr[], int low, int high, int num) {
	if (low > high) {
		return -1;
	}
	int mid = low + high / 2;
	if (num == arr[mid]) {
		return mid;
	}
	else if (num < arr[mid]) {
		return recursiveBs(arr, low, mid - 1, num);
	}
	else {
		return recursiveBs(arr, mid + 1, high, num);
	}
}
//iteration, both took log(n) time, took O(1) space, recursion may take O(log(n)) space beacuse of the increment of stack
/*
Conclusion
Both will have the same time complexity O(log(n)), but they will different in term of space usage.
Recursive May reach to "log(n)" space (because of the stack), in iterative BS it should be "O(1)" space complexity.

At the point of choice of recursive vs. iterative formulation is pretty much a matter of personal and local preference.
Some people find recursive code easier to understand. Some people are scared to death of recursion, or don't understand it, or have no clue about tail recursion optimization, and want explicitly iterative code everywhere.
*/

//int Bs::passingbyRef(int&arr) {
//	int length = *(&arr + 1) - arr;
//	return length;
//}