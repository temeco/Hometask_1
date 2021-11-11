#include<iostream>
#include "ArrayFunctions.h"

using namespace std;

int main(int argc, char* argv[])
{
    int n = 0;
    cout << "Enter integer: ";
	cin >> n;
    const int N = 180;
    int basic[N]{ 0 };
	int* arr = new int[n] { 0 };

    randomizeArray(arr,n);
    printArray(arr, n);
    cout << sumOfElements(arr,n) << endl;
    cout << productOfNegatives(arr,n) << endl;
    cout << countOfEven(arr,n) << endl;
    cout << secondMin(arr, n) << endl;
    cout << indSecMax(arr,n) << endl;
    swapElem(arr,n);
    printArray(arr,n);

    reverseArray(arr,n);
    printArray(arr,n);
    
    deleteMiddle(arr,n);
    printArray(arr,n);

    insertZero(arr,n);
    printArray(arr,n);
 
    delete[] arr;

	return EXIT_SUCCESS;
}